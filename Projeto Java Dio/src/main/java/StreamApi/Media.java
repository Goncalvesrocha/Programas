/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package StreamApi;

import java.util.Arrays;
import java.util.List;
import java.util.function.BinaryOperator;


/**
 * @Objetivo: Calcular a média dos números maiores que 5
 * @author Pichau
 */
public class Media {
    public static void main(String[] args) {
        List <Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3);
        
        //Expressão Lamba 
        BinaryOperator <Integer> somar = (n1, n2) -> n1 + n2;
        
        //Stream API
        int resultado = numeros.stream()
                           .filter(n -> n > 5) 
                           .reduce(0, somar);
        
        System.out.println(resultado);
              
    }
    
}
