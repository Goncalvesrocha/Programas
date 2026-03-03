/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasList;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Pichau
 */
public class CarrinhoDeCompras {
    
    private List<Item> carrinho;
    
    public CarrinhoDeCompras(){
        this.carrinho = new ArrayList<>();
    }
    
    public void adicionarItem(String nome, double preco, int quantidade){
        carrinho.add(new Item(nome, preco, quantidade));
    }
    
    public void removerItem(String nome){
        List <Item> itensParaRemover = new ArrayList();
         for(Item i : carrinho){
             if(i.getNome().equalsIgnoreCase(nome)){
                 itensParaRemover.add(i);
             }
        }
         carrinho.removeAll(itensParaRemover);
    }
    
    public double calcularValorTotal(){
        double total = 0.0;
        for(int i = 0; i < carrinho.size(); i++){
             total = carrinho.get(i).getPreco() * 
                     carrinho.get(i).getQuantidade() + total;
        }
        
        return total;
    }
    
    public void exibirItens(){
        System.out.println(carrinho);
    }
      
    
}
