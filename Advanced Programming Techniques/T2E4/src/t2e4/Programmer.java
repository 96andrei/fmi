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
public class Programmer extends Person{
    
    String language;
    
    public Programmer(String name, int age, String language) {
        super(name, age);
        this.language = language;
    }
    
    @Override
    public String toString(){
        return name + " " + age + " " + language + ";";
    }
    
}
