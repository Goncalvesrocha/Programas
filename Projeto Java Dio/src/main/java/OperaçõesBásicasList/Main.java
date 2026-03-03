/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasList;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        CarrinhoDeCompras teste = new CarrinhoDeCompras();
        
        teste.adicionarItem("Estojo", 19.99, 2);
        teste.adicionarItem("Mochila", 30.50, 1);
        teste.adicionarItem("Mouse", 54.53, 1);
        teste.adicionarItem("Lixeira", 15.80, 5);
        
        System.out.println(teste.calcularValorTotal());
        teste.exibirItens();
        
        teste.removerItem("Estojo");
        
        System.out.println(teste.calcularValorTotal());
        teste.exibirItens();
    }
}
