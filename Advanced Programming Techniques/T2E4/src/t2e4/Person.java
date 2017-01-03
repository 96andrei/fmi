/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t2e4;

/**
 *
 * @author a96an
 */
public class Person implements Comparable {

    int age;
    String name;
    
    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }
    
    public int getAge(){
        return age;
    }
    
    @Override
    public int compareTo(Object t) {
        Person p = (Person)t;
        return age - p.getAge();
    }
    
    @Override
    public String toString(){
        return name + " " + age + ";";
    }
}
