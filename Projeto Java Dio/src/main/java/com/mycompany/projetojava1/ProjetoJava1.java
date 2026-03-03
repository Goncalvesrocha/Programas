/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.projetojava1;

/**
 *
 * @author Pichau
 */
public class ProjetoJava1 {

    private String nome;
    private int idade;
    private float altura;
    int teste;
    String nome2;
    
     public ProjetoJava1(String nnome, String nnome2, int idado, float autura, float media){
              
       idado = idado + 5;
       autura = 100 * (autura - media);
       teste = nnome.compareTo(nnome2);
       
       nome = nnome;
       idade = idado;
       altura = autura;
       
   }
   
   public void Mostrar(){
       System.out.println("Nome: " + nome 
                          + "\nIdade em 2030: " + idade
                          + "\nDiferenca de altura:" + altura + " cm"
                          + "\nTeste de Strings: " + teste);
   }
       
}  
  /*  USANDO GETTERS E SETTERS:

   public String getNome(){ 
       return nome;
   }
   
   public int getIdade(){ 
       return idade;
   }
   
   public float getAltura(){ 
       return altura;
   }
   
   
   public void setDados(String Novonome, int Novaidade, float Novaaltura){ //Setters
      nome = Novonome;
      idade = Novaidade;
      altura = Novaaltura;
   }
 */  
       
  
  
