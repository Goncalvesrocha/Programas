/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OperaçõesBásicasSet;

import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Pichau
 */
public class ConjuntoConvidados {
    
    private Set <Convidado> convidadosSet;

    public ConjuntoConvidados() {
        this.convidadosSet = new HashSet<>();
    }
    
    public void adicionarConvidado(String nome, int codigo){
            convidadosSet.add(new Convidado(nome, codigo));
    }
    
    public void removerConvidadoPorCodigoConvite(int codigo){
            Convidado convidadoRemover = null;
            for(Convidado c : convidadosSet){
                if(c.getCodigo() == codigo){
                   convidadoRemover = c;
                    break;
                }
            }
            convidadosSet.remove(convidadoRemover);
    }
    
    public int contarConvidados(){
        return convidadosSet.size();
    }
    
    public void exibirConvidados(){
        System.out.println(convidadosSet);
    }
}
