/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaList;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Pichau
 */
public class CatalogoLivros {
    private List <Livro> livrosList;

    public CatalogoLivros() {
        this.livrosList = new ArrayList<>();
    }
    
    public void adicionarLivro(String titulo, String autor, int ano){
        livrosList.add(new Livro(titulo, autor, ano));
    }
    
    public List<Livro> pesquisarPorAutor(String autor){
        List <Livro> pesquisarLivro = new ArrayList<>();
        
        if(!livrosList.isEmpty()){
            for(int i = 0; i < livrosList.size(); i++){
                if(livrosList.get(i).getAutor().equalsIgnoreCase(autor)){
                    pesquisarLivro.add(livrosList.get(i));
                }
            }
        }
        return pesquisarLivro;
    }
    
    public List<Livro> pesquisarPorIntervaloAnos(int anoInicial, int anoFinal){
        List <Livro> pesquisarLivro = new ArrayList<>();
        
        if(!livrosList.isEmpty()){
            for(int i = 0; i < livrosList.size(); i++){
                if(livrosList.get(i).getAno() >= anoInicial && livrosList.get(i).getAno() <= anoFinal)
                    pesquisarLivro.add(livrosList.get(i));
            }
        }
        return pesquisarLivro;
    }
    
    public Livro pesquisarPorTitulo(String titulo){
        Livro pesquisarLivro = null;
        
        if(!livrosList.isEmpty()){
            for(int i = 0; i < livrosList.size(); i++){
                if(livrosList.get(i).getTitulo().equalsIgnoreCase(titulo))
                    pesquisarLivro = livrosList.get(i);
                    break;
            }
        }
        return pesquisarLivro;
    }
    
}
