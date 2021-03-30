/*
*    Author:           Azizz Mills, Sharome Burton
*    Email:            azizzmillz@gmail.com, koulkoudakis@gmail.com
*    Label:            P02
*    Title:            GraphViz C++ Code 
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*
*    Description:
*         This program gives the output of the code for grapviz to be
*         copied and pasted into the Graphviz program compiler. 
*         It is done by taking the aspects or syntax of the Graphviz
*         API and converting it into C++ code.
*
*    Repl Link: 
*         https://replit.com/@Koulkoudakis/P02-GraphViz-C-Code#main.cpp
*         
*    Usage:
*        - $ ./main filename
*        
*    Files:
*          main.cpp
*          input.txt
*          
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
/*
Class name: Input
Decription: Reads data from a text file into to be used 
*/

class Input
{
public:

  vector<string>vecAbbrev;  // Country abbreviations
  vector<string>vecCountry; // Full country names
  vector<string>vecColors;  // Node colors
  vector<string>vecStartNodes;  // Start point for edges
  vector<string>vecEndNodes;    // End point for edges
  vector<string>vecEdgeLabels;  // Labels for edges

  int E; // number of edges

   /*
   Name: import()

   Function: reads data form the text file and places them into multiple vectors 

   Parameters: -infile (used to retrieve data from the file), 
               -graphsize (used to set end condition of number of nodes to be counted by for loop)

   Usage:  - $ ./main filename   
   */
	void import(ifstream& infile, int graphsize) 
	{
		string node_id;     // Country abbreviations
    string node_label;  // Country names
    string node_color;  // Node colors

    string start_node_id; // Start point for edges
    string end_node_id;   // End point for edges
    int edge_label;       // Labels for edge


    // Reads in node ID, label, and color (optional)
		for (int count = 0; count < graphsize; count++)
		{
      // * Uncomment to enable reading in node colors
      // (at your own risk!)
      //infile >> node_color;     
      //vecColors.push_back(node_color);

			infile >> node_label;
      vecCountry.push_back(node_label);

			infile >> node_id;
      vecAbbrev.push_back(node_id);
		}			   	

    infile >> E;  // Number of edges expected from input file

    // Read in edges from input file
    for (int count = 0; count < E; count++)
		{
			infile >> start_node_id;
			vecStartNodes.push_back(start_node_id);

			infile >> end_node_id;
      vecEndNodes.push_back(end_node_id);

      infile >> edge_label;
      vecEdgeLabels.push_back(to_string(edge_label));
		}			
	}		   	  
};
/*
Name: GraphDynamics

Decription: this is where the data collected will be used to output code in the Graphviz API 
*/
class GraphDynamics : public Input
{
public:
  int x = 34;   
	char quotation = static_cast<char>(x); 
  // since the ASCII code for " is 34, the functions changes x to "

/*
Name: labels()

Function: Outputs the node ID and label

Parameters: -outfile(sends output to a text file), 
            -graphsize(used to set end condition of number of nodes to be    counted by for loop),
            -vecAbbrev(contains abbreviations data),
            -vecCountry(contains name of Countries)

Usage: - $ ./main filename
*/
	void labels(ofstream& outfile, int graphsize, vector<string> vecAbbrev, vector<string> vecCountry)
	{
		
		for (int count = 0; count < graphsize; count++)
		{
			outfile << vecAbbrev[count] << " [label=" << quotation << vecCountry[count] << quotation<< "]" << '\n';
		}
    
	}
/*
Name: labelsAndColors()

Function: Outputs the node ID, label and colors

Parameters: -outfile(sends output to a text file), 
            -graphsize(used to set end condition of number of nodes to be counted by for loop),
            -vecAbbrev(contains abbreviations data),
            -vecCountry(contains name of Countries)
            -vecColors(changes the color of the nodes)

Usage: - $ ./main filename
*/
  void labelsAndColors(ofstream& outfile, int graphsize, vector<string> vecAbbrev, vector<string> vecCountry, vector<string> vecColors)
	{
		
		for (int count = 0; count < graphsize; count++)
		{
			outfile << vecAbbrev[count] << " [label=" << quotation << vecCountry[count] << quotation <<" [color=" << vecColors[count]<< quotation<< "]" << '\n';
		}
	}

/*
Name: edges()

Function: Outputs the node ID, label and the miles 

Parameters: -outfile(sends output to a text file),
            -graphsize(intialize size of vector),
            -vecStartNodes(starting poins of the edges)
            -vecEndNodes(end points of the edges),
            -vecEdgeLabels()

Usage: - $ ./main filename
*/
  void edges(ofstream& outfile, int E, vector<string> vecStartNodes, vector<string> vecEndNodes, vector<string> vecEdgeLabels)
	{
		
		for (int count = 0; count < E; count++)
		{
			outfile << vecStartNodes[count] << " -> " << vecEndNodes[count] << " [label=" << quotation << vecEdgeLabels[count]<< " miles" << quotation << "]" << '\n';
		}
    
    outfile << "}\n\n"; // close graph definition
	}
};

int main()
{
	
	string graph; // Type of graph

	int graphsize; // Number of nodes in graph

	ifstream infile;
	infile.open("input.txt");
  ofstream outfile;
  outfile.open("output.txt");

	infile >> graph;  
	infile >> graphsize;  

  Input a;
	GraphDynamics b;

  // Begins definition of graph for Graphviz
	outfile << graph << "{" << '\n';

  // Stores input file contents into Input file object
	a.import(infile, graphsize); 
  
  // Outputs node ID's and labels to output file
	b.labels(outfile, graphsize,a.vecCountry,a.vecAbbrev);

  // Outputs edge start points, end points and labels to output file
  b.edges(outfile, a.E, a.vecStartNodes, a.vecEndNodes, a.vecEdgeLabels);
	
	return 0;
}