#define MyAnalysis_cxx
// The class definition in MyAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    Begin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("MyAnalysis.C")
// Root > T->Process("MyAnalysis.C","some options")
// Root > T->Process("MyAnalysis.C+")
//0.

#include "MyAnalysis.h"
#include <iostream>
#include <TH1F.h>
#include <TLatex.h>

using namespace std;

void MyAnalysis::BuildEvent() {
   
   Muons.clear();
   for (int i = 0; i < NMuon; ++i) {
      MyMuon muon(Muon_Px[i], Muon_Py[i], Muon_Pz[i], Muon_E[i]);
      muon.SetIsolation(Muon_Iso[i]);
      muon.SetCharge(Muon_Charge[i]);
      Muons.push_back(muon);
   }
   
   Electrons.clear();
   for (int i = 0; i < NElectron; ++i) {
      MyElectron electron(Electron_Px[i], Electron_Py[i], Electron_Pz[i], Electron_E[i]);
      electron.SetIsolation(Electron_Iso[i]);
      electron.SetCharge(Electron_Charge[i]);
      Electrons.push_back(electron);
   }
   
   Photons.clear();
   for (int i = 0; i < NPhoton; ++i) {
      MyPhoton photon(Photon_Px[i], Photon_Py[i], Photon_Pz[i], Photon_E[i]);
      photon.SetIsolation(Photon_Iso[i]);
      Photons.push_back(photon);
   }
   
   Jets.clear();
   for (int i = 0; i < NJet; ++i) {
      MyJet jet(Jet_Px[i], Jet_Py[i], Jet_Pz[i], Jet_E[i]);
      jet.SetBTagDiscriminator(Jet_btag[i]);
      jet.SetJetID(Jet_ID[i]);
      Jets.push_back(jet);
   }
   
   hadB.SetXYZM(MChadronicBottom_px, MChadronicBottom_py, MChadronicBottom_pz, 4.8);
   lepB.SetXYZM(MCleptonicBottom_px, MCleptonicBottom_py, MCleptonicBottom_pz, 4.8);
   hadWq.SetXYZM(MChadronicWDecayQuark_px, MChadronicWDecayQuark_py, MChadronicWDecayQuark_pz, 0.0);
   hadWqb.SetXYZM(MChadronicWDecayQuarkBar_px, MChadronicWDecayQuarkBar_py, MChadronicWDecayQuarkBar_pz, 0.0);
   lepWl.SetXYZM(MClepton_px, MClepton_py, MClepton_pz, 0.0);
   lepWn.SetXYZM(MCneutrino_px, MCneutrino_py, MCneutrino_pz, 0.0);
   met.SetXYZM(MET_px, MET_py, 0., 0.);
   
   EventWeight *= weight_factor;
   
}

void MyAnalysis::Begin(TTree * /*tree*/) {
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
}

void MyAnalysis::SlaveBegin(TTree * /*tree*/) {
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
/*   h_Mmumu = new TH1F("Mmumu", "Invariant di-muon mass", 60, 60, 120);
   h_Mmumu->SetXTitle("m_{#mu#mu}");
   h_Mmumu->Sumw2();
   histograms.push_back(h_Mmumu);
   histograms_MC.push_back(h_Mmumu);
   
   h_Mmumu_s1 = new TH1F("Mmumu_s1", "Invariant di-muon mass_s1", 60, 60, 120);
   h_Mmumu_s1->SetXTitle("m_{#mu#mu}");
   h_Mmumu_s1->Sumw2();
   histograms.push_back(h_Mmumu_s1);
   histograms_MC.push_back(h_Mmumu_s1);
   
   h_Mmumu_s2 = new TH1F("Mmumu_s2", "Invariant di-muon mass_s2", 60, 60, 120);
   h_Mmumu_s2->SetXTitle("m_{#mu#mu}");
   h_Mmumu_s2->Sumw2();
   histograms.push_back(h_Mmumu_s2);
   histograms_MC.push_back(h_Mmumu_s2);
   
   h_Mmumu_s3 = new TH1F("Mmumu_s3", "Invariant di-muon mass_s3", 60, 60, 120);
   h_Mmumu_s3->SetXTitle("m_{#mu#mu}");
   h_Mmumu_s3->Sumw2();
   histograms.push_back(h_Mmumu_s3);
   histograms_MC.push_back(h_Mmumu_s3);
  */ 
   h_NJet = new TH1F("NJet", "Number of jets", 7, 0, 7);
   h_NJet->SetXTitle("No. Jets");
   h_NJet->Sumw2();
   histograms.push_back(h_NJet);
   histograms_MC.push_back(h_NJet);
   
   h_NJet_s1 = new TH1F("NJet", "Number of jets_s1", 7, 0, 7);
   h_NJet_s1->SetXTitle("No. Jets_s1");
   h_NJet_s1->Sumw2();
   histograms.push_back(h_NJet_s1);
   histograms_MC.push_back(h_NJet_s1);
   
   h_NJet_s2 = new TH1F("NJet", "Number of jets_s2", 7, 0, 7);
   h_NJet_s2->SetXTitle("No. Jets_s2");
   h_NJet_s2->Sumw2();
   histograms.push_back(h_NJet_s2);
   histograms_MC.push_back(h_NJet_s2);
   
   h_NJet_s3 = new TH1F("NJet", "Number of jets_s3", 7, 0, 7);
   h_NJet_s3->SetXTitle("No. Jets_s3");
   h_NJet_s3->Sumw2();
   histograms.push_back(h_NJet_s3);
   histograms_MC.push_back(h_NJet_s3);
   
   h_NBJet = new TH1F("NBJet", "Number of b-jets", 7, 0, 7);
   h_NBJet->SetXTitle("No. BJets");
   h_NBJet->Sumw2();
   histograms.push_back(h_NBJet);
   histograms_MC.push_back(h_NBJet);
   
   h_NBJet_s1 = new TH1F("NBJet_s1", "Number of b-jets_s1", 7, 0, 7);
   h_NBJet_s1->SetXTitle("No. BJets_s1");
   h_NBJet_s1->Sumw2();
   histograms.push_back(h_NBJet_s1);
   histograms_MC.push_back(h_NBJet_s1);
   
   h_NBJet_s2 = new TH1F("NBJet_s2", "Number of b-jets_s2", 7, 0, 7);
   h_NBJet_s2->SetXTitle("No. BJets_s2");
   h_NBJet_s2->Sumw2();
   histograms.push_back(h_NBJet_s2);
   histograms_MC.push_back(h_NBJet_s2);
   
   h_NBJet_s3 = new TH1F("NBJet_s3", "Number of b-jets_s3", 7, 0, 7);
   h_NBJet_s3->SetXTitle("No. BJets_s3");
   h_NBJet_s3->Sumw2();
   histograms.push_back(h_NBJet_s3);
   histograms_MC.push_back(h_NBJet_s3);
   
   h_NMuon = new TH1F("NMuon", "Number of muons", 7, 0, 7);
   h_NMuon->SetXTitle("No. Muons");
   h_NMuon->Sumw2();
   histograms.push_back(h_NMuon);
   histograms_MC.push_back(h_NMuon);
   
   h_NElectron = new TH1F("NElectron", "Number of electrons", 7, 0, 7);
   h_NElectron->SetXTitle("No. Electrons");
   h_NElectron->Sumw2();
   histograms.push_back(h_NElectron);
   histograms_MC.push_back(h_NElectron);
   
  
   h_selectedEvents_Muon1_Pt = new TH1F("selectedEvents_Muon1_Pt", "Pt of muon1 (selected)", 40, 0, 200);
   h_selectedEvents_Muon1_Pt->SetXTitle("p_{T, selected} [GeV]");
   h_selectedEvents_Muon1_Pt->Sumw2();
   histograms.push_back(h_selectedEvents_Muon1_Pt);
   histograms_MC.push_back(h_selectedEvents_Muon1_Pt);
   
   h_selectedEvents_triggered_Muon1_Pt = new TH1F("selectedEvents_triggered_Muon1_Pt",
                                                  "Pt of muon1 (selected and triggered)", 40, 0, 200);
   h_selectedEvents_triggered_Muon1_Pt->SetXTitle("p_{T, triggered} [GeV]");
   h_selectedEvents_triggered_Muon1_Pt->Sumw2();
   histograms.push_back(h_selectedEvents_triggered_Muon1_Pt);
   histograms_MC.push_back(h_selectedEvents_triggered_Muon1_Pt);
   
    
}

Bool_t MyAnalysis::Process(Long64_t entry) {
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MyAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   
   ++TotalEvents;
   
   GetEntry(entry);
   
   if (TotalEvents % 10000 == 0)
      cout << "Next event -----> " << TotalEvents << endl;
   
   BuildEvent();
   
   double MuonPtCut = 25.;
   double MuonRelIsoCut = 0.10;
   
   //   cout << "Jets: " << endl;
   //   for (vector<MyJet>::iterator it = Jets.begin(); it != Jets.end(); ++it) {
   //      cout << "pt, eta, phi, btag, id: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->IsBTagged() << ", " << it->GetJetID()
   //      << endl;
   //   }
   //   cout << "Muons: " << endl;
   //   for (vector<MyMuon>::iterator it = Muons.begin(); it != Muons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Electrons: " << endl;
   //   for (vector<MyElectron>::iterator it = Electrons.begin(); it != Electrons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Photons: " << endl;
   //   for (vector<MyPhoton>::iterator it = Photons.begin(); it != Photons.end(); ++it) {
   //      cout << "pt, eta, phi, iso: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->GetIsolation()
   //      << endl;
   //   }
   
   
   //////////////////////////////
   // Exercise 1: Invariant Di-Muon mass
   
   int N_IsoMuon = 0;
   MyMuon *muon1, *muon2;
   
   for (vector<MyMuon>::iterator jt = Muons.begin(); jt != Muons.end(); ++jt) {
      if (jt->IsIsolated(MuonRelIsoCut)) {
         ++N_IsoMuon;
         if (N_IsoMuon == 1) muon1 = &(*jt);
         if (N_IsoMuon == 2) muon2 = &(*jt);
      }
   }
   
   h_NMuon->Fill(N_IsoMuon, EventWeight);
   
   int NJet = 0;
   int NBJet = 0;
   for (vector<MyJet>::iterator jt = Jets.begin(); jt != Jets.end(); ++jt) {
        NJet = NJet + 1;
        MyJet *jet = &(*jt);
        bool isbtagged = jet->IsBTagged();
        if ( isbtagged )
          NBJet++;
   }
   //cout << "number of jets = " << nJets << endl;
   //cout << "number of b jets = " << nbJets << endl;
  
   double met_pt = met.Pt();

   if (N_IsoMuon > 0 && triggerIsoMu24) {

     /* if (muon1->Pt()>MuonPtCut) {
          h_Mmumu_s1->Fill(met_pt, EventWeight);
          h_NJet_s1->Fill(NJet, EventWeight);
          h_NBJet_s1->Fill(NBJet, EventWeight);
*/
        if ( NJet>= 1){
          h_NJet_s1->Fill(NJet, EventWeight);
          //h_NBJet_s2->Fill(NBJet, EventWeight);
            
          if ( NJet>= 2){
             //h_Mmumu_s2->Fill(met_pt, EventWeight);
            h_NJet_s2->Fill(NJet, EventWeight);
              //h_NBJet_s2->Fill(NBJet, EventWeight);

            if ( NJet>= 3){
              //h_NBJet_s3->Fill(NBJet, EventWeight); 
             // h_Mmumu_s3->Fill(met_pt, EventWeight);
              h_NJet_s3->Fill(NJet, EventWeight);
              }

           }
           
         }  
      

   
   //////////////////////////////
   
   
   //////////////////////////////
   // Exercise 2: MC / data comparisons
   
   int N_BJet = 0;
   for (vector<MyJet>::iterator jt = Jets.begin(); jt != Jets.end(); ++jt) {
      if (jt->IsBTagged()) {
         ++N_BJet;
      }
   }
   
   int N_Jet = 0;
   int N_BJet_tmp = 0;
         if ( NBJet>= 1){
            h_NBJet_s1->Fill(NBJet, EventWeight);
            
            if ( NBJet>= 2){
              h_NBJet_s2->Fill(NBJet, EventWeight);
              
              if ( NBJet>= 3){
                h_NBJet_s3->Fill(NBJet, EventWeight);
                }
              }
           }        
   h_NJet->Fill(NJet, EventWeight);
   h_NBJet->Fill(NBJet, EventWeight);
   
   
   int N_Electron = 0;
   for (vector<MyElectron>::iterator it = Electrons.begin(); it != Electrons.end(); ++it) {
      if  (it->IsIsolated()) {
          ++N_Electron;
      }
   }
   
   h_NElectron->Fill( N_Electron , EventWeight);
   
 
   //////////////////////////////
   // Exercise 3: Trigger turn on
   if (Muons.size() == 1) {
      if (Muons.at(0).IsIsolated(MuonRelIsoCut)) {
         h_selectedEvents_Muon1_Pt->Fill(Muons.at(0).Pt(), EventWeight);
         if (triggerIsoMu24)
            h_selectedEvents_triggered_Muon1_Pt->Fill(Muons.at(0).Pt(), EventWeight);
      }
   }
   //////////////////////////////
   
   //////////////////////////////
   // Exercise 3: Acceptance Efficiency
   GeneratedEvents += EventWeight;
   bool IsSelected = false;
   if (N_IsoMuon == 1) {
      if (muon1->Pt()>MuonPtCut) {
         
         int NBJet = 0;
         for (vector<MyJet>::iterator it = Jets.begin(); it != Jets.end(); ++it) {
            if (it->IsBTagged()) {
               ++NBJet;
            }
         }
         if (NBJet > 1) {
            SelectedEvents += EventWeight*SF_b*SF_b;
            if (triggerIsoMu24) {
               SelectedEvents_triggered += EventWeight*SF_b*SF_b;
               IsSelected = true;
            }
         }
         
      }
   }
   //////////////////////////////
  
  
   return kTRUE;
}

}
void MyAnalysis::SlaveTerminate() { 
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.   
}

void MyAnalysis::Terminate() {
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
}


