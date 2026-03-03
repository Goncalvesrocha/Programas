/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasListExercicio;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Pichau
 */
public class ListaTarefas {
    
   //Declarando uma variável List
   private List<Tarefa> tarefaList; 
   
   /*Construtor que cria uma nova ArrayList do zero sempre que for 
   inicializada*/
   public ListaTarefas(){
       this.tarefaList = new ArrayList<>();
   }
   
   public void adicionarTarefa(String descricao){
        tarefaList.add(new Tarefa(descricao));
   }
   
   public void removerTarefa(String descricao){
       List <Tarefa> tarefasParaRemover = new ArrayList();
         for(Tarefa t : tarefaList){
             if(t.getDescricao().equalsIgnoreCase(descricao)){
                 tarefasParaRemover.add(t);
             }
        }
         tarefaList.removeAll(tarefasParaRemover);
                
   }
   
   public int obterNumeroTotalTarefas(){
       return tarefaList.size();
   }
   
   public void obterDescricoesTarefas(){
       System.out.println(tarefaList);    
   }
   
   
}
