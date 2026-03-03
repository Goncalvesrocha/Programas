/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasMap;

import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Pichau
 */
public class AgendaContatos {
    private Map <String, Integer> agendaContatoMap;

    public AgendaContatos() {
        this.agendaContatoMap = new HashMap<>();
    }
    
    public void adicionarContato(String nome, Integer telefone){
        agendaContatoMap.put(nome, telefone);
    }
    
    public void removerContato(String nome){
        if(!agendaContatoMap.isEmpty()){
            agendaContatoMap.remove(nome);
        }
    }
    
    public void exibirContatos(){
        System.out.println(agendaContatoMap);
    }
    
    public Integer pesquisarPorNome(String nome){
         if(!agendaContatoMap.isEmpty()){
            return agendaContatoMap.get(nome);
        }
         return -1; // Erro
    }
            
}
