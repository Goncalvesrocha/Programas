/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package StreamApi;

import java.util.Arrays;
import java.util.List;
import java.util.function.BinaryOperator;

/**
 * @Objetivo: Exibir números acima de 10 dentro da lista
 * @author Pichau
 */
public class MaiorQue10 {
    public static void main(String[] args) {
        List <Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3);
        
        //Stream API
        numeros.stream()
               .filter(n -> n > 10) 
               .forEach(System.out::println); // Nenhum número será printado
            
    }
}
