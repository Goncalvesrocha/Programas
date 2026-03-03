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
public class MeiaIngresso extends Ingresso{
    
    @Override
    public void setPreco(double valor){
       this.preco = valor;
    }
    @Override
    public double exibirPreco(){
        return preco/2.0;
    }
    
}
