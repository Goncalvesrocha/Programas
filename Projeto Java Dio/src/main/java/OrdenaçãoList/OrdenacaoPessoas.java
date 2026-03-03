/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OrdenaçãoList;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author Pichau
 */
public class OrdenacaoPessoas {
    private List <Pessoas> fila;

    public OrdenacaoPessoas() {
        this.fila = new ArrayList<>();
    }
    
    public void adicionarPessoas(String nome, int idade, double altura){
        fila.add(new Pessoas(nome, idade, altura));
    }
    
    public List<Pessoas> ordenarPorIdade(){
       List<Pessoas> pessoasIdade = new ArrayList(fila);
       Collections.sort(pessoasIdade);
       return pessoasIdade;
    }
    
    public List<Pessoas> ordenarPorAltura(){
       List<Pessoas> pessoasAltura = new ArrayList(fila);
       Collections.sort(pessoasAltura, new ComparatorPorAltura());
       return pessoasAltura;
    }
    
}
