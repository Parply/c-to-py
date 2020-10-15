#include <iostream>
#include <string>
#include <vector>




double HUE2RGB(double p,double q,double t)
{
	
	if (t<0) t+=1.0;
	if (t>1) t-=1.0;
	if (t<1.0/6.0) return p+(q-p) *6.0*t;
	if (t<1.0/2.0) return q;
	if (t<2.0/3.0) return p+(q-p)*(2.0/3.0-t)*6.0;
	return p;
}

void HSL2RGB(double h,double sl,double l,char * hexcol)
{
	double r = 0.0,g=0.0,b=0.0;
	if (sl ==0){
		r=g=b=(l*255.0);
	} else {

	
		double q = (l<=0.5) ? (l*(1.0+sl)) : (l+sl-l*sl);
	
		double p = 2.0*l-q;
		r= (255.0*HUE2RGB(p, q, h +1.0/3.0))+0.5;
		g = (255.0*HUE2RGB(p, q, h))+0.5;
		b = (255.0*HUE2RGB(p, q, h-1.0/3.0))+0.5;
	}
	
	std::snprintf(hexcol,sizeof(hexcol),"%02X%02X%02X",(int)r,(int)g,(int)b);

	

}

void Rainbow(int numOfSteps,int step,char *hexcol)
{
	double pos= (double) step / double (numOfSteps);

	HSL2RGB(pos, 1.0, 0.5, hexcol);
}


int main()
{
	int numOfSteps = 20;
	char hexcol[16];
	std::vector<std::string> colours(numOfSteps);
	#pragma omp parallel for shared(colours,numOfSteps) private(hexcol)
	for (int i=0; i<numOfSteps;i++)
	{
		Rainbow(numOfSteps, i,hexcol);
		
		colours.at(i)=hexcol;
		
		
	}
	
	for (auto i:colours){
		std::cout << i << std::endl;
	}
	return 0;
}
