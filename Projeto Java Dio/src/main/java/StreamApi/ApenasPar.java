/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package StreamApi;

import java.util.Arrays;
import java.util.List;
import java.util.function.BinaryOperator;
import java.util.function.Consumer;
import java.util.function.Predicate;


/**
 * @Objetivo: Usar Stream API para filtrar e mostrar apenas números pares 
 *
 * 
 * @author Pichau
 */
public class ApenasPar {
    public static void main(String[] args) {
        
        List <Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 4, 3);
  
       numeros.stream()
          .filter(n -> n % 2 == 0)
          .forEach(System.out::println);
    }
          
 }
