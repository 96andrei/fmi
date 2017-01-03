#include <fstream>
#include <stack>
using namespace std;

int main(){
	int t;

	ifstream fin("editor.in");
	ofstream fout("editor.out");

    fin>>t;

    for(int i = 0; i <t; i++){
        stack<char> stack;
        char c;
        string str = "";

        fin>>c;
        while(c!='E'){
            if(c=='*' && str!=""){
                str.erase(str.end()-1);
            }else if(c != '*')
                str+=c;
            fin>>c;
        }

        c=str[0];
        int j=0;
        while(c != '\0'){
            if(c == ')'){
                if(stack.size() == 0)
                    stack.push(c);
                else if(stack.top() == '('){
                    stack.pop();
                }else{
                    stack.push(c);
                }
            }
            else if(c == ']'){
                if(stack.size() == 0)
                    stack.push(c);
                else if(stack.top() == '['){
                    stack.pop();
                }else{
                    stack.push(c);
                }

            }
            else{
                stack.push(c);
            }
            j++;
            c = str[j];
        }

        if(stack.size() == 0)
            fout<<":)"<<endl;
        else
            fout<<":("<<endl;
    }

    fin.close();
    fout.close();

    return 0;
}
