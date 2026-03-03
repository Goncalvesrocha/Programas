/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaMap;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        EstoqueProdutos estoque = new EstoqueProdutos();
        
        estoque.adicionarProduto(2L, "A", 1, 7.66);
        estoque.adicionarProduto(4L, "B", 2, 5.32);
        
        estoque.exibirProdutos();
        
        System.out.println(estoque.calcularValorTotalEstoque());
        System.out.println(estoque.ProdutoMaisCaro());
        
    }
}
