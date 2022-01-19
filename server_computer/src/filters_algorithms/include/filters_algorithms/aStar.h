#pragma once
#ifndef ASTAR_H
#define ASTAR_H
#include<iostream>
#include<math.h>
#include <limits.h>
#define Row (21)
#define column (42)
namespace AStar {
	struct Node 
	{ int x, y; 
	float dist;
	Node* next;
	};
	class AStarSearch
	{
	public:
		AStarSearch(struct Node& Start, struct Node& Des,int[Row][column]);
		~AStarSearch() { }
		void startSearch();
		void drawRoute(Node*);
		struct Node* getMinDistNode(void);
		float calculateHeuristicValue(int,int);
		int oned_ind(struct Node*);
		Node* route(void);
		struct Node* twod_ind(int);
		bool isDestination(struct Node*);
		bool isStart(int, int);
		bool isObstacle(int, int);
		bool isValidNode(int, int);
		bool isVisitedNode(int, int);
	private:
		int input_map[Row][column];
		float f_map[Row][column];
		float g_map[Row][column];
		int parent[Row][column];
		Node* start,* des;
		static int totalNodeExpanded;

	};
};
#endif //!ASTAR_H