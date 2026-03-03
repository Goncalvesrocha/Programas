/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Interfaces;

/**
 *
 * @author Pichau
 */
public class Smartphone implements VideoPlayer, MusicPlayer{

    @Override
    public void playVideo() {
        System.out.println("Rolando o vídeo");
    }

    @Override
    public void pauseVideo() {
        System.out.println("Pausando o vídeo");
    }

    @Override
    public void stopVideo() {
        System.out.println("Saíndo do vídeo");
    }

    @Override
    public void playMusic() {
        System.out.println("Tocando música");
    }

    @Override
    public void pauseMusic() {
        System.out.println("Pausando a música");
    }

    @Override
    public void stopMusic() {
       System.out.println("Saindo da música");
    }
    
}
