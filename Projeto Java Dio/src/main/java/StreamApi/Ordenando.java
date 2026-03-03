/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package StreamApi;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

/**
 * @Objetivo: Usar Stream API para ordenar uma lista de números
 * @author Pichau
 */
public class Ordenando {
    public static void main(String[] args) {
        
        List <Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3);
        
        numeros.stream()
             .sorted()
             .forEach(System.out::println);

        numeros.stream()
                .sorted()
                .forEach(System.out::println);
    }
}
