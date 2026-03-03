/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exercício1;
import Exercício1.Ingresso;

/**
 *
 * @author Pichau
 */
public class IngressoFamilia extends Ingresso {
    
    private int numPessoas;
    private double desconto = 0.0;
    
    public void setNumPessoas(int quant){
        this.numPessoas = quant;
    }
   
    @Override
    public void setPreco(double valor){
       this.preco = valor;
    }
      
    @Override
    public double exibirPreco(){
        desconto = preco * 0.05;
        System.out.println(desconto);
        return preco * numPessoas - desconto;
    }
    
}
