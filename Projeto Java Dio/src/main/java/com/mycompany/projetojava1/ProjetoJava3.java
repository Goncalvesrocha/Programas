/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.projetojava1;

/**
 *
 * @author Pichau
 */
//Extends - Herda uma classe
//Non-sealed - Não é selada, logo, pode haver heranças não intencionadas
public non-sealed class ProjetoJava3 extends ProjetoJava2{
     
    private String login;
    
    private String password;
    
    private double commission;
    
    public String getLogin(){
       return login; 
    }
    
    public String getPassword(){
       return password; 
    }
     
    public double getCommission(){
       return commission; 
    }
      
    public void setLogin(String log){
          login = log;
    }
      
    public void setPassword(String senha){
          password = senha;
    }
       
    public void setCommission(double com){
          commission = com;
    }
}
