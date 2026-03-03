/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaSet;

import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Pichau
 */
public class AgendaContatos {
    
    private Set <Contato> contatosSet;

    public AgendaContatos() {
        this.contatosSet = new HashSet<>();
    }
    
    public void adicionarContato(String nome, int numero){
        contatosSet.add(new Contato(nome, numero));
    }
    
    public void exibirContatos(){
        System.out.println(contatosSet);
    }
    
    public Set<Contato> pesquisarPorNome(String nome){
        Set <Contato> pesquisaNome = new HashSet<>();
        for(Contato c : contatosSet){
            if(c.getNome().startsWith(nome)){
                pesquisaNome.add(c);
            }
        }
        return pesquisaNome;
    }
    
    public Contato atualizarNumeroContato(String nome, int novoNumero){
        Contato atualizado = null;
        for(Contato c : contatosSet){
            if(c.getNome().equalsIgnoreCase(nome)){
                c.setNumero(novoNumero);
                atualizado = c;
                break;
            }
        }
        return atualizado;
    }
    
}
