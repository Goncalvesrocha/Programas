/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasMap;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        AgendaContatos instancia = new AgendaContatos();
        
        instancia.adicionarContato("Jao", 12345);
        instancia.adicionarContato("Cleilson", 24521);
        instancia.adicionarContato("Julio", 22124);
        instancia.adicionarContato("Roberval", 98209);
        instancia.adicionarContato("Linton", 21731);
        
        instancia.exibirContatos();
        
        instancia.removerContato("Linton");
        instancia.exibirContatos();
        
        System.out.println(instancia.pesquisarPorNome("Jao"));
    }
}
