/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaMap;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Pichau
 */
public class EstoqueProdutos {
    
    private Map <Long, Produto> estoqueProdutosMap;

    public EstoqueProdutos() {
        this.estoqueProdutosMap = new HashMap<>();
    }
    
    public void adicionarProduto(long cod, String nome, int quantidade, double preco){
        this.estoqueProdutosMap.put(cod, new Produto(nome, preco, quantidade));
    }
    
    public void exibirProdutos(){
        System.out.println(estoqueProdutosMap);
    }
    
    public double calcularValorTotalEstoque(){
        double valorTotal = 0d;
        if(!estoqueProdutosMap.isEmpty()){

            for(Produto p: estoqueProdutosMap.values())
            {
                valorTotal += p.getPreco() * p.getQuantidade();
            }
        }
        return valorTotal;
    }
    
    public Produto ProdutoMaisCaro(){
        
        Produto produtoCaro = null;
        double maiorPreco = Double.MIN_VALUE;
        
        for(Produto p: estoqueProdutosMap.values()){
            if(p.getPreco() > maiorPreco)
                produtoCaro = p;
        }
        return produtoCaro;
        
    }
    
}
