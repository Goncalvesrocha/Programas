/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.projetojava1;

/**
 *
 * @author Pichau
 * Classe de Empregado
 */

//Abstract - Não tem como instanciar usando esta classe para passar o valor
//Sealed, permits -  É herdada apenas ás classes permitidas; heranças seletivas

 public sealed abstract class ProjetoJava2 permits ProjetoJava3{
    
    private String code;
    
    private String name;
    
    private String address;
    
    private String salary;
    
    public String getCode(){
        return code; 
    }
    
    public void setCode(String codigo){
        code = codigo;
    }
    
    public String getName(){
        return name;
    }
    
    public void setName(String nome){
        name = nome;
    }
    
    public String getAddress(){
        return address;
    }
    
    public void setAddress(String ender){
        address = ender;
    }
    
    public String getSalary(){
        return salary;
    }
    public void setSalary(String salario){
        salary = salario;
    }
    
    
}
