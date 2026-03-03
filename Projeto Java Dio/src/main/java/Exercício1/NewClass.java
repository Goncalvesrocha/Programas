/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exercício1;

import java.util.Scanner;
/**
 *
 * @author Pichau
 */
public class NewClass {
    
    public static void main(String[] args) {
        Ingresso ticket = new Ingresso();
        Scanner read = new Scanner(System.in);
        
        System.out.println("1 - Jornada das Estrelas --R$20,00\n2 - Jujustu Kaise: Hidden inventory/Premature death--R$32,00\n3 - Batman--R$22,00");
        int opcao = read.nextInt();
        
        switch(opcao){
            
            case 1 -> {
                ticket.setNomeFilme("Jornada das Estrelas");
                System.out.println("Jornada das Estrelas, dublado(true) ou legendado(false)?");
                ticket.setIdioma(read.nextBoolean());
                ticket.setPreco(20.0);
            }
                
            case 2 -> {
                ticket.setNomeFilme("Jujutsu Kaisen: Hidden inventory/Premature death");
                System.out.println("Jujutsu Kaisen: Hidden inventory/Premature death, dublado(true) ou legendado(false)?");
                ticket.setIdioma(read.nextBoolean());
                ticket.setPreco(32.0);
            }
                
            case 3 -> {
                ticket.setNomeFilme("Batman");
                System.out.println("Batman, dublado(true) ou legendado(false)?");
                ticket.setIdioma(read.nextBoolean());
                ticket.setPreco(22.0);
            }
                
            default -> {
                System.out.println("Escolha uma opcao valida! Tente novamente, mais tarde.");
            }
        }
        System.out.println("Quantas pessoas? ");
        int pessoas = read.nextInt();
        
        if(pessoas > 3){
            IngressoFamilia familia = new IngressoFamilia();
            familia.setNumPessoas(opcao);
            familia.setPreco(20);
            System.out.println(familia.exibirPreco());
        }
        else if (pessoas > 0 && pessoas <= 3){
            MeiaIngresso cupom = new MeiaIngresso();
            System.out.println(cupom.exibirPreco());
        }
        else
            System.out.println("Opcao invalida! KKKKK.\n Como assim " + pessoas + " PESSOAS?KKKKKKKKK LOL");
        
    }
    
}
