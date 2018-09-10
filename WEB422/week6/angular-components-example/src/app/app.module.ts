import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header.component';
import { ContentComponent } from './content.component';
import { FooterComponent } from './footer.component';
import { HorseComponent } from './horse.component';
import { LizardComponent } from './lizard.component';
import { PageNotFoundComponent } from './page-not-found.component';
import { HomeComponent } from './home.component';
import { BearComponent } from './bear.component';
import { EagleComponent } from './eagle.component';
import { DolphinComponent } from './dolphin.component';
import { NavbarComponent } from './navbar.component';
import { SidebarComponent } from './sidebar.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    ContentComponent,
    FooterComponent,
    HorseComponent,
    LizardComponent,
    PageNotFoundComponent,
    HomeComponent,
    BearComponent,
    EagleComponent,
    DolphinComponent,
    NavbarComponent,
    SidebarComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
