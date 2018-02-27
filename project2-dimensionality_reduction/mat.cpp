#include <iostream>
#include "mat.hpp"

using namespace std;

Mat::Mat(const char* tr, const char* te, const uint& _features, 
            const uint& _classes, double (*_compFunc)(const string &))
{

    classes = _classes;
    features = _features;
    compFunc = _compFunc;
    readFile(tr, X);
    readFile(te, Xte);
    nX = subMatrix(X, 0, 0, X.getRow() -1, features - 1);
    nXte = subMatrix(Xte, 0, 0, Xte.getRow() -1, features -1);
    normalize(nX, nXte, features, 1);

    for(int i = 0; i < classes; i++)
    {
        Matrix t2 = getType(X, i);
        sig.push_back( cov(t2, features) );
        mu.push_back( mean(t2, features) );
    }
}

void
Mat::readFile(const char* fName, Matrix &_X)
{
    vector<Sample> d;
    double samp[features+1];
    string tmp;
    ifstream input(fName);

    if(! input.is_open() )
    {
        fprintf(stderr, "Unable to open %s, exiting.\n", fName);
        exit(1);
    }
    getline(input, tmp);
    while( getSamp(input, samp) )
    {
        Sample s(features, samp);
        d.push_back(s);
    }
    input.close();
    buildMatrix(d, _X);
}

bool
Mat::getSamp(ifstream &input, double samp[])
{
    int i;
    string tmp;

    for(i = 0; i < features && (input >> samp[i]); i++);
    if( i < features) return false;

    input >> tmp;
    samp[i] = compFunc(tmp);
    
    return true;
}

void
Mat::buildMatrix(vector<Sample> &c, Matrix & _X)
{
    int sz = c.size();
    _X.createMatrix(sz, features+1);
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < features + 1; j++)
            _X(i, j) = c[i][j];
}

void
Mat::PCA(float maxErr)
{
    pX = nX;
    pXte = nXte;
    int numDrop = pca(pX, pXte, features, maxErr, 1);
    pX = subMatrix(pX, 0, 0, pX.getRow() - 1, numDrop - 1);
    pXte = subMatrix(pXte, 0, 0, pXte.getRow() - 1, numDrop - 1);
    addLabels(pX, X);
    addLabels(pXte, Xte);
    for( int i =  0; i < classes; i++)
    {
        Matrix m = getType(pX, i);
        pMu.push_back( mean(m, m.getCol() ) );
        pSig.push_back( cov(m, m.getCol() ) );
    }
}

void
Mat::addLabels(Matrix &dest, const Matrix & src)
{
    Matrix tmp(dest.getRow(), dest.getCol() + 1);
    uint lab_ind = src.getCol() - 1;
    uint i, j;
    for(i = 0; i < dest.getRow(); i++)
    {
        for(j = 0; j < dest.getCol(); j++)
            tmp(i, j) = dest(i, j);
        tmp(i, j) = src(i, lab_ind);
    }
    dest = tmp;
}

void
Mat::FLD()
{
    Matrix mVec;
    mVec = mu[0];
    fW = (sig[0].getRow() - 1) * sig[0];
    for(uint i = 1; i < classes; i++)
    {
        mVec = mVec - mu[i];
        fW = fW + (sig[i].getRow() - 1) * sig[i];
    }
    Matrix sW = fW;
    fW = inverse(fW) ->* mVec;
    mVec = mVec ->* transpose(mVec);
    Matrix lossFunc = ( transpose(fW) ->* mVec ->* fW)
                    / ( transpose(fW) ->* sW ->* fW);
    cout << mVec << lossFunc;
    /*
        fW is omega is 7x1
        mVec is Sb and is 7x7
        sW is also 7x7
        
        Next, need to transform data set
    */
}

ostream& 
operator<<(ostream &os, const Sample &s)
{
    for(int i = 0; i < s.sample.size(); i++)
        os << s.sample[i] << " ";
    os << endl;
    return os;
}
