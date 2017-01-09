using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EarCutting : MonoBehaviour {

    class Polygon {
        public List<Vector2> points;
        public LineRenderer lineRenderer;
        public LineRenderer cutsRenderer;

        List<Vector3> cuts;

        public void Draw() {
            Vector3[] positions = new Vector3[points.Count + 1];
            for (int i = 0; i < points.Count; i++) {
                positions[i] = points[i];
            }

            positions[points.Count] = positions[0];
            lineRenderer.numPositions = points.Count + 1;
            lineRenderer.SetPositions(positions);
        }

        public int FindNextEar() {
            int i = 0;
            bool earNotFound = true;
            while (earNotFound) {
                Debug.Log("Checking " + i);
                if (IsConvex(i)) {
                    Debug.Log(i + " is convex");
                    earNotFound = false;
                    for (int j = GetNextIndex(GetNextIndex(i)); j != GetPrevIndex(i); j = GetNextIndex(j)) {
                        Debug.Log("Is in triangle " + j);
                        if (IsConvex(j))
                            continue;
                        if (IsInTriangle(points[GetPrevIndex(i)], points[i], points[GetNextIndex(i)], points[j])) {
                            earNotFound = true;
                            break;
                        }
                    }
                }
                if (earNotFound)
                    i++;
            }

            //Debug.Log("Found " + i);
            return i;
        }

        float Area(Vector2 a, Vector2 b, Vector2 c) {
            return Mathf.Abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
        }

        bool IsInTriangle(Vector2 a, Vector2 b, Vector2 c, Vector2 p) {
            float area = Area(a, b, c);

            return Eqals(area, Area(a, b, p) + Area(b, c, p) + Area(a, c, p));
        }

        bool Eqals(float x, float y) {
            if (Mathf.Abs(x - y) < 1e-5)
                return true;
            return false;
        }

        public void CutEar(int index) {
            points.RemoveAt(index);
        }

        public int GetPrevIndex(int i) {
            //Debug.Log("Prev of " + i + " is " + (i > 0 ? i - 1 : points.Count - 1));
            return i > 0 ? i - 1 : points.Count - 1;
        }

        public int GetNextIndex(int i) {
            return i < points.Count - 1 ? i + 1 : 0;
        }

        public bool IsConvex(int i) {
            Debug.Log("IS CONVEX " + i);
            Vector2 prev = i > 0 ? points[i - 1] : points[points.Count - 1];
            Vector2 next = i < points.Count - 1 ? points[i + 1] : points[0];
            //print(Orient(prev, points[i], next));
            return Orient(prev, points[i], next) > 0;
        }

        public bool IsConcave(int i) {
            //Debug.Log("IS CONCAVE " + points[i]);
            Vector2 prev = i > 0 ? points[i - 1] : points[points.Count - 1];
            Vector2 next = i < points.Count - 1 ? points[i + 1] : points[0];
            return Orient(prev, points[i], next) < 0;
        }

        int Orient(Vector2 a, Vector2 b, Vector2 c) {
            float result = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
            //Debug.Log(a + " " + b + " " + c + " " + result);
            if (result < 0) //left
                return -1;
            if (result > 0) //right
                return 1;
            return 0;
        }

    }

    class Triangle {
        Vector3 p1;
        Vector3 p2;
        Vector3 p3;
        public LineRenderer lr = null;
        public Triangle(Vector2 a, Vector2 b, Vector2 c) {
            p1 = a;
            p2 = b;
            p3 = c;
            p1.z = 5;
            p2.z = 5;
            p3.z = 5;
        }

        public void Draw(GameObject renderer) {
            GameObject obj = Instantiate(renderer);
            lr = obj.GetComponent<LineRenderer>();
            Vector3[] points = new Vector3[4];
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;
            points[3] = p1;
            lr.SetPositions(points);
            obj.SetActive(true);
        }
    }

    Vector2 Phi(Vector2 x) {
        //Define the affine transformation
        //Consider Phi defined as follows
        //Phi(x) = A*x + b where b is a Vector from R^2 and A is a linear transformation
        //Will consider the matrix form of this affine transformation as  [y1,y2] = A * [x1, x2] + [b1,b2] where A is a matrix of 2x2 like [a,b\c,d]
        //The will be calculated as follows:  y1 = (a*x1 + b*x2) + b1  and y2 = (c*x1 + d*x2) + b2
        //So we just need to read a,b,c,d and b1,b2
        //Will consider them constant 
        //const float a = 1, b=0, c=0, d=2 , b1 = 0, b2 = 0; // this is going to reprezent the scalation
        float y1, y2;
        float x1, x2;
        x1 = x.x;
        x2 = x.y;

        y1 = (a * x1 + b * x2) + b1;
        y2 = (c * x1 + d * x2) + b2;

        Vector2 y = new Vector2(y1, y2);
        return y;
    }

    void GetTheImage() {
        foreach (Vector2 x in points) {
            Vector2 y = Phi(x);
            pointsTransformed.Add(y);
        }
    }

    [Header("Point Info")]
    public List<Vector2> points;
    public bool counterClockWise = true;
    public List<Vector2> pointsTransformed;
    Polygon p;
    Polygon pT;

    [Header("Graphics Info")]
    [SerializeField]
    GameObject knob;
    [SerializeField]
    GameObject triangleRenderer;

    [SerializeField]
    LineRenderer pRend;
    [SerializeField]
    LineRenderer pTRend;

    bool step = true;
    bool stepT = true;
    int lastEar = -1;
    int lastEarT = -1;

    List<Triangle> triangles;
    List<Triangle> trianglesTransformed;

    [Header("Phi Info")]
    public float a = 1;
    public float b = 0;
    public float c = 0;
    public float d = 2;
    public float b1 = 0;
    public float b2 = 0;

    [Header("Message Info")]
    [SerializeField]
    GameObject text;


    void Start() {
        triangles = new List<Triangle>(); ;
        trianglesTransformed = new List<Triangle>();
        p = new Polygon();
        if (!counterClockWise)
            points.Reverse();
        p.points = points;
        p.lineRenderer = pRend;


        //Debug.Log(p.FindEar());
        //
        p.Draw();

        pT = new Polygon(); //the poligon obtained from the image of p through the affine function 
        GetTheImage();
        if (!counterClockWise)
            pointsTransformed.Reverse();

        if(a*d < 0 || b*c >0)
            pointsTransformed.Reverse();

        pT.points = pointsTransformed;
        pT.lineRenderer = pTRend;

    }

    void Update() {
        if (Input.GetKeyDown(KeyCode.C) && p.points.Count > 2) {
            if (step) {
                lastEar = p.FindNextEar();
                knob.transform.position = p.points[lastEar];

            } else {
                triangles.Add(new Triangle(p.points[p.GetPrevIndex(lastEar)], p.points[lastEar], p.points[p.GetNextIndex(lastEar)]));
                triangles[triangles.Count - 1].Draw(triangleRenderer);
                p.CutEar(lastEar);
                p.Draw();

                if (p.points.Count <= 2) {
                    knob.SetActive(false);
                    p.lineRenderer.enabled = false;
                }
            }
            step = !step;
        }

        if (Input.GetKeyDown(KeyCode.D)) {
            p.lineRenderer.enabled = false;
            foreach (Triangle g in triangles)
                if (g.lr != null)
                    g.lr.gameObject.SetActive(false);
            knob.SetActive(true);
            pT.lineRenderer.enabled = true;
            pT.Draw();
        }

        if (Input.GetKeyDown(KeyCode.N) && pT.points.Count > 2) {
            if (stepT) {
                lastEarT = pT.FindNextEar();
                knob.transform.position = pT.points[lastEarT];

            } else {
                trianglesTransformed.Add(new Triangle(pT.points[pT.GetPrevIndex(lastEarT)], pT.points[lastEarT], pT.points[pT.GetNextIndex(lastEarT)]));
                trianglesTransformed[trianglesTransformed.Count - 1].Draw(triangleRenderer);
                pT.CutEar(lastEarT);
                pT.Draw();

                if (pT.points.Count <= 2) {
                    knob.SetActive(false);
                    pT.lineRenderer.enabled = false;
                }
            }
            stepT = !stepT;
        }

        if (points.Count < 3 && triangles[0].lr.gameObject.activeInHierarchy == true)
            text.SetActive(true);
        else
            text.SetActive(false);

        if(pointsTransformed.Count < 3 )
            text.SetActive(true);

    }

}
