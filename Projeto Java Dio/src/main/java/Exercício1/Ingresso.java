/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exercício1;

/**
 *
 * @author Pichau
 */
public class Ingresso 
{
    public double preco;
    public String nomeFilme;
    public boolean dublado;
    
    public void setNomeFilme(String filme){
        this.nomeFilme = filme;
    }
    
    public void setPreco(double valor){
       this.preco = valor;
    }
  
    public void setIdioma(boolean idioma){
        this.dublado = idioma;
    }
    
    public double exibirPreco(){
        return preco;
    }
    
}
