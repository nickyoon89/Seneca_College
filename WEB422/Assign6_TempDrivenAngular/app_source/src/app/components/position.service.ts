import { Injectable } from '@angular/core';
import { Observable} from "rxjs";
import { HttpClient} from "@angular/common/http"

import { Position } from './position';

@Injectable()
export class PositionService {

  private url = "https://web422-server.herokuapp.com";

  constructor(private http: HttpClient) { }

  getPositions(): Observable<Position[]> {
    return this.http.get<Position[]>(this.url+"/positions")
  }

  savePosition(position: Position) {
    return this.http.put<any>(
      "https://web422-server.herokuapp.com/position/" + position._id, position
    );
  }

  getPosition(id: string): Observable<Position[]> {
    return this.http.get<Position[]>(
      "https://web422-server.herokuapp.com/position/" + id
    );
  }
}