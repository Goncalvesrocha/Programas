/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasSet;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        ConjuntoConvidados conjunto = new ConjuntoConvidados();
        System.out.println("Existem " + conjunto.contarConvidados() + " convidados "
                + "dentro do Set de Convidados");
        
        conjunto.adicionarConvidado("Cleber", 12);
        conjunto.adicionarConvidado("Tamaria", 13);
        conjunto.adicionarConvidado("Wilson", 13);
        conjunto.adicionarConvidado("Anderson", 14);
        
        conjunto.removerConvidadoPorCodigoConvite(12);
        conjunto.exibirConvidados();
        
    }
    
}
