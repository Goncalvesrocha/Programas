/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OrdenaçãoList;

import java.util.Comparator;

/**
 *
 * @author Pichau
 */
public class Pessoas implements Comparable <Pessoas>{
    
    private String nome;
    private int idade;
    private double altura;
    
    public Pessoas(String nome, int idade, double altura){
        this.nome = nome;
        this.idade = idade;
        this.altura = altura;
    }
    
    
    @Override
    public int compareTo(Pessoas o) {
        return Integer.compare(idade, o.getIdade());
    }

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public double getAltura() {
        return altura;
    }
    //Sobreescreve o endereço de memória

    @Override
    public String toString() {
        return "Pessoas{" + "nome=" + nome 
                + ", idade=" + idade 
                + ", altura=" + altura 
                + '}';
    } 
}

class ComparatorPorAltura implements Comparator<Pessoas>{

    @Override
    public int compare(Pessoas o1, Pessoas o2) {
        return Double.compare(o1.getAltura(), o2.getAltura());
    }
    
}
