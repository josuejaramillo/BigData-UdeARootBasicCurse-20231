int SeguimientoRead() {
    Int_t Npart;
    std::vector<Int_t> *det = nullptr;
    std::vector<Float_t> *energy = nullptr;
    std::vector<Float_t> *time  =   nullptr;

    TFile f ("manyparticles.root", "READ");
    TTree *t = (TTree*) f.Get ("tree");
    t->SetBranchAddress ("Npart", &Npart);
    t->SetBranchAddress ("Det"  , &det    );
    t->SetBranchAddress ("Time" , &time   );
    t->SetBranchAddress ("En"   , &energy );

    cout << "* This tree has " 
        << t->GetEntries() << " entries.\n\n";
    t->Print();
    for (int ievt=0; ievt<t->GetEntries(); ievt++) 
    {
      t->GetEntry(ievt);
      cout << "* Event " << ievt 
          << " has " << Npart << " particles:\n";
    

      for (int ipart=0; ipart<Npart; ipart++) 
      {
        cout << setw(10) << det->at(ipart)
            << setw(12) << time->at(ipart)
            << setw(12) << energy->at(ipart) << endl;
     }
    }
    return 0;
  }
