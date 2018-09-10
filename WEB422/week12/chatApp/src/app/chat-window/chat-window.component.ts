import { Component, OnInit } from '@angular/core';
import {ChatService} from '../chat.service';

@Component({
  selector: 'app-chat-window',
  templateUrl: './chat-window.component.html',
  styleUrls: ['./chat-window.component.css']
})
export class ChatWindowComponent implements OnInit {

  private getMessagesSub: any;
  messages: string[] = [];
  currentMessage: string;

  constructor(private chatService: ChatService) { }

  ngOnInit() {
    this.getMessagesSub = this.chatService.getMessages.subscribe((data) => {
      this.messages.push(data);
    });
  }    

  sendMessage(){
    this.chatService.sendMessage(this.currentMessage);
    this.currentMessage = "";
  }

  ngOnDestroy(){    
     if(this.getMessagesSub){this.getMessagesSub.unsubscribe();}   
  } 

}
