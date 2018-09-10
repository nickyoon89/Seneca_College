import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppComponent } from './app.component';
import { AppRoutingModule } from "./app-routing.module";
import { HeaderComponent } from './header.component';
import { NavmainComponent } from './navmain.component';
import { ContentComponent } from './content.component';
import { FooterComponent } from './footer.component';
import { HorseComponent } from './horse.component';
import { LizardComponent } from './lizard.component';
import { PageNotFoundComponent } from './page-not-found.component';
import { StartComponent } from './start.component';
import { GuideComponent } from './guide.component';
import { BearComponent } from './bear.component';
import { EagleComponent } from './eagle.component';
import { DolphinComponent } from './dolphin.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    NavmainComponent,
    ContentComponent,
    FooterComponent,
    HorseComponent,
    LizardComponent,
    PageNotFoundComponent,
    StartComponent,
    GuideComponent,
    BearComponent,
    EagleComponent,
    DolphinComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
