/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PesquisaList;

/**
 *
 * @author Pichau
 */
public class Livro {
    
    private String titulo;
    private String autor;
    private int ano;
    
    public Livro(String titulo, String autor, int ano){
        this.titulo = titulo;
        this.autor = autor;
        this.ano = ano;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAno() {
        return ano;
    }
    //Sobreescreve o endereço de memória
    @Override
    public String toString() {
        return "Livro{" + "titulo=" + titulo 
                + ", autor=" + autor 
                + ", ano=" + ano + '}';
    }
    
   
}
