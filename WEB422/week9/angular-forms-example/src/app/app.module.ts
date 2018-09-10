import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from "@angular/forms";

import { HttpClientModule } from "@angular/common/http";

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
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
import { FormV1Component } from './form-v1.component';

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
    DolphinComponent,
    FormV1Component
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
