/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.projetojava1;

/**
 *
 * @author Pichau
 */
public class Main {


      public static void main(String[] args) {
        /*
        ProjetoJava1 var = new ProjetoJava1("Ronaldinho", "Ponaldinho",  38 , 1.82f, 1.75f);
        var.Mostrar();
        */
        printEmployee(new ProjetoJava3());
       
        
      }
    
    
      public static void printEmployee(ProjetoJava2 empregado){
        
        System.out.printf("======%s======\n", empregado.getClass().getCanonicalName());
        
        switch(empregado){
            case ProjetoJava3 manager ->{
                
               manager.setCode("1234");
               manager.setName("Igor");
               manager.setAddress("Rua Solimoes");
               manager.setSalary("4500");
               manager.setLogin("ala");
                
                
                System.out.println(manager.getCode());
                System.out.println(manager.getName());
                System.out.println(manager.getAddress());
                System.out.println(manager.getSalary());
                System.out.println(manager.getLogin());
            }
        }
        System.out.println("============");  
    }
}
