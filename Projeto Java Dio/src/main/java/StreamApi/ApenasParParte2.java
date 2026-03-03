/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package StreamApi;

import java.util.Arrays;
import java.util.List;

/**
 * @Objetivo: Eliminar os números ímpares da lista e mostrar a lista resultante
 * @author Pichau
 */
public class ApenasParParte2 {
    public static void main(String[] args) {
        List <Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3);
        
        List <Integer> pares =  numeros.stream()
                                    .filter(n -> n % 2 == 0)
                                    .toList();
        
        System.out.println(pares);
              
    }
}
