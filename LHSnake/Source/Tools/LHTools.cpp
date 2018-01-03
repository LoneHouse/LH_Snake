//
//  LHTools.cpp
//  LHSnake
//
//  Created by Victor Privalov on 1/16/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#include "LHTools.hpp"

void LHTools::LoadObjectFromFile(std::string filePath)
{
    using namespace std;
    using namespace LH::Render;
    vector<Figure> results;
    
    ifstream fileStream(filePath, std::ios::in);
    
    if (fileStream.is_open()) {
        
        string line;
        while (getline(fileStream, line)) {
            
            istringstream lineStream(line);
            
            string param;
            if (lineStream >> param) {
                cout << "I Got Param : " << param << endl;
                
                //Skip comments
                if (param == "#") {
                    continue;
                }
                
                if (param == "o") {
                    string name;
                    lineStream >> name;
                    results.push_back(Figure(name));
                    continue;
                }
                
                if (param == "v") {
                    float vertex_x;
                    float vertex_y;
                    float vertex_z;
                    
                    lineStream >> vertex_x;
                    lineStream >> vertex_y;
                    lineStream >> vertex_z;
                    
                    results[results.size()-1].vertices.push_back(Vertex(vertex_x,vertex_y,vertex_z));
                    
                    continue;
                }
                
                if (param == "vn") {
                    float normal_x;
                    float normal_y;
                    float normal_z;
                    
                    lineStream >> normal_x;
                    lineStream >> normal_y;
                    lineStream >> normal_z;
                    
                    results[results.size()-1].vertices.push_back(Vertex(normal_x,normal_y,normal_z));
                    
                    continue;
                }
                
                if (param == "f") {
                    
                    int vertex_number;
                    int vertex_texture_number;
                    int vertex_normal_number;
                    
                    string face;
                    lineStream >> face;
                    istringstream faceStream(face);
                    getline(faceStream, face, '/');
                    
                    
                    
                }
                
                
            } else {
                continue;
            }
            
            
        }
        
        //THIS Shit is treat string as Stream with Tokens
        //            std::ilineStream  lineStream(line);
        //            int a, b;
        //            if (!(iss >> a >> b)) { break; } // error
        
        
    } else {
        throw "Can't open file with object [" + filePath + "]\n";
    }
    
    
    fileStream.close();
}
