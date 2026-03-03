/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Interfaces;

/**
 *
 * @author Pichau
 */
public class Main {
    public static void main(String[] args) {
     /*
       //Classe Anônima: declara a classe durante a instância
       var musicPlayer = new MusicPlayer(){
       
       @Override
       public void playMusic(){
           System.out.println("Tocando a música");
       }
       @Override
       public void pauseMusic(){
           
       }
       @Override
       public void stopMusic(){
           
       }
     };
       musicPlayer.pauseMusic();
     */
     
     //runMusic();
     //runVideo();
    
   }
    public static void runVideo(VideoPlayer mp4){
        mp4.playVideo();
    }
    
    public static void runMusic(MusicPlayer mp3){
        mp3.playMusic();
    }
    
}
