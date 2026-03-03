/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OrdenaçãoList;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
        OrdenacaoPessoas pessoas = new OrdenacaoPessoas();
        pessoas.adicionarPessoas("Lucas", 23, 1.67);
        pessoas.adicionarPessoas("Jorge", 45, 1.85);
        pessoas.adicionarPessoas("São Batista", 15, 1.55);
        
        System.out.println(pessoas.ordenarPorIdade());
        System.out.println(pessoas.ordenarPorAltura());
       
    }
}
