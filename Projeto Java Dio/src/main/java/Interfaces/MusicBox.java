/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Record.java to edit this template
 */
package Interfaces;

/**
 *
 * @author Pichau
 */
public record MusicBox(String music, boolean isPaused) implements MusicPlayer {
    
    @Override
    public void playMusic(){
        System.out.println("Music box tocando música");   
    }
    
    @Override
    public void pauseMusic(){
        System.out.println("Music box pausando a música");
    }
    
    @Override
    public void stopMusic(){
        System.out.println("Music box saindo da música");
    }
    
}

