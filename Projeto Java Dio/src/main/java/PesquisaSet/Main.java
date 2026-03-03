/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaSet;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        AgendaContatos obj = new AgendaContatos();
        
        obj.adicionarContato("Maria", 11242);
        obj.adicionarContato("Nora", 145535);
        obj.adicionarContato("Maria Silva", 235365);
        
        System.out.println(obj.pesquisarPorNome("Maria"));
        
        obj.exibirContatos();
        
        obj.atualizarNumeroContato("Nora", 1);
        
        obj.exibirContatos();
    }
}
