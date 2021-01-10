#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void wait()
{
    /*
        FUNCTION TO HOLD THE PROGRAM TO LET THE USER EXAMINE THE CURRENT SITUATION 
    */

    printf("\nPress enter to continue...\n");
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void print_1d_array(int arr[], int n)
{
    printf("\n");
    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[i]);
}

void sort_array(int arr[], int n) 
{   
    for (int i = n - 1; i > 0; i--) { 
  
        int max_index = 0; 
        for (int j = 1; j <= i; j++) 
        {
            if (arr[j] < arr[max_index])
            {
                max_index = j; 
            } 
        }
  
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    } 
}

void argsort_array(int arr[], int indices[], int n) 
{   
    /*
        SORTING AN ARRAY WHILE KEEPING TRACK OF ITS INDICES 
    */

    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }


    for (int i = n - 1; i > 0; i--) { 
  
        int max_index = 0; 
        for (int j = 1; j <= i; j++) 
        {
            if (arr[j] < arr[max_index])
            {
                max_index = j; 
            }
        }

        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
  

        int temp_ = indices[i];
        indices[i] = indices[max_index];
        indices[max_index] = temp_;
    }
}



int roll_dice()
{
    int num = rand() % 6 + 1;
    return num;
}

int ask_num_players()
{
    int num_players;

    // Ask again until the user gives a valid input
    while (num_players < 2 || num_players > 4)
    {
        printf("Give the number of players. Input should be between 2 and 4: ");
        scanf("%d", &num_players);
    }

    return num_players;
}

void determine_play_order(int num_players, int playing_order[])
{
    /*
        EVERY PLAYER ROLLS A DICE AND DICES ARE SORTED WITH ARGSORT
        TO DETERMINE IN WHICH ORDER THEY WILL BE PLAYING
    */

    int dices[num_players];
    for (int i = 0; i < num_players; i++)
    {
        wait();
        dices[i] = roll_dice();
        printf("PLAYER %d ROLLS THE DICE... RESULT IS: %d\n", i + 1, dices[i]);
    }

    argsort_array(dices, playing_order, num_players);
}

void build_board(char board[9][9][20], char P[], char EMP[], char board_cell_castle_names[][4][20], char board_cell_home_names[][4][20])
{
    /*
        BUILDING THE BOARD WITH DEFAULT VALUES
    */

    strncpy(board[0][0], board_cell_castle_names[0][0], 20);
    strncpy(board[0][1], board_cell_castle_names[0][1], 20);
    strncpy(board[0][2], EMP, 20);
    strncpy(board[0][3], P, 20);
    strncpy(board[0][4], P, 20);
    strncpy(board[0][5], P, 20);
    strncpy(board[0][6], EMP, 20);
    strncpy(board[0][7], board_cell_castle_names[1][0], 20);
    strncpy(board[0][8], board_cell_castle_names[1][1], 20);

    strncpy(board[1][0], board_cell_castle_names[0][3], 20);
    strncpy(board[1][1], board_cell_castle_names[0][2], 20);
    strncpy(board[1][2], EMP, 20);
    strncpy(board[1][3], P, 20);
    strncpy(board[1][4], board_cell_home_names[1][2], 20);
    strncpy(board[1][5], P, 20);
    strncpy(board[1][6], EMP, 20);
    strncpy(board[1][7], board_cell_castle_names[1][3], 20);
    strncpy(board[1][8], board_cell_castle_names[1][2], 20);

    strncpy(board[2][0], EMP, 20);
    strncpy(board[2][1], EMP, 20);
    strncpy(board[2][2], EMP, 20);
    strncpy(board[2][3], P, 20);
    strncpy(board[2][4], board_cell_home_names[1][1], 20);
    strncpy(board[2][5], P, 20);
    strncpy(board[2][6], EMP, 20);
    strncpy(board[2][7], EMP, 20);
    strncpy(board[2][8], EMP, 20);

    strncpy(board[3][0], P, 20);
    strncpy(board[3][1], P, 20);
    strncpy(board[3][2], P, 20);
    strncpy(board[3][3], P, 20);
    strncpy(board[3][4], board_cell_home_names[1][0], 20);
    strncpy(board[3][5], P, 20);
    strncpy(board[3][6], P, 20);
    strncpy(board[3][7], P, 20);
    strncpy(board[3][8], P, 20);

    strncpy(board[4][0], P, 20);
    strncpy(board[4][1], board_cell_home_names[0][2], 20);
    strncpy(board[4][2], board_cell_home_names[0][1], 20);
    strncpy(board[4][3], board_cell_home_names[0][0], 20);
    strncpy(board[4][4], EMP, 20);
    strncpy(board[4][5], board_cell_home_names[3][0], 20);
    strncpy(board[4][6], board_cell_home_names[3][1], 20);
    strncpy(board[4][7], board_cell_home_names[3][2], 20);
    strncpy(board[4][8], P, 20);

    strncpy(board[5][0], P, 20);
    strncpy(board[5][1], P, 20);
    strncpy(board[5][2], P, 20);
    strncpy(board[5][3], P, 20);
    strncpy(board[5][4], board_cell_home_names[2][0], 20);
    strncpy(board[5][5], P, 20);
    strncpy(board[5][6], P, 20);
    strncpy(board[5][7], P, 20);
    strncpy(board[5][8], P, 20);

    strncpy(board[6][0], EMP, 20);
    strncpy(board[6][1], EMP, 20);
    strncpy(board[6][2], EMP, 20);
    strncpy(board[6][3], P, 20);
    strncpy(board[6][4], board_cell_home_names[2][1], 20);
    strncpy(board[6][5], P, 20);
    strncpy(board[6][6], EMP, 20);
    strncpy(board[6][7], EMP, 20);
    strncpy(board[6][8], EMP, 20);

    strncpy(board[7][0], board_cell_castle_names[2][0], 20);
    strncpy(board[7][1], board_cell_castle_names[2][1], 20);
    strncpy(board[7][2], EMP, 20);
    strncpy(board[7][3], P, 20);
    strncpy(board[7][4], board_cell_home_names[2][2], 20);
    strncpy(board[7][5], P, 20);
    strncpy(board[7][6], EMP, 20);
    strncpy(board[7][7], board_cell_castle_names[3][0], 20);
    strncpy(board[7][8], board_cell_castle_names[3][1], 20);

    strncpy(board[8][0], board_cell_castle_names[2][3], 20);
    strncpy(board[8][1], board_cell_castle_names[2][2], 20);
    strncpy(board[8][2], EMP, 20);
    strncpy(board[8][3], P, 20);
    strncpy(board[8][4], P, 20);
    strncpy(board[8][5], P, 20);
    strncpy(board[8][6], EMP, 20);
    strncpy(board[8][7], board_cell_castle_names[3][3], 20);
    strncpy(board[8][8], board_cell_castle_names[3][2], 20);
}

void print_board(char board[9][9][20])
{
    printf("\n-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 9; i++)
    {
        printf("| ");
        for (int j = 0; j < 9; j++)
        {
            int k = 0;
            while (board[i][j][k] != '\0')
            {
                printf("%c", board[i][j][k]);
                k++;
            }
            printf(" | ");
        }
        printf("\n-------------------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

void place_initial_pieces(char board[9][9][20],
                            int player_piece_positions[][4][2],
                            int num_players,
                            char all_pieces[][4][20])
{
    /* 
    
        PLACING THE PIECES OF THE PLAYERS IN THEIR CASTLES ACCORDING TO THE NUMBER OF PLAYERS
        AND DETERMINING THE INITIAL PIECE POSITIONS
     */

    if (num_players >= 2)
    {
        strncpy(board[0][0], all_pieces[0][0], 20);
        strncpy(board[0][1], all_pieces[0][1], 20);
        strncpy(board[1][0], all_pieces[0][3], 20);
        strncpy(board[1][1], all_pieces[0][2], 20);

        strncpy(board[0][7], all_pieces[1][0], 20);
        strncpy(board[0][8], all_pieces[1][1], 20);
        strncpy(board[1][7], all_pieces[1][3], 20);
        strncpy(board[1][8], all_pieces[1][2], 20);

        player_piece_positions[0][0][0] = 0;
        player_piece_positions[0][0][1] = 0;

        player_piece_positions[0][1][0] = 0;
        player_piece_positions[0][1][1] = 1;

        player_piece_positions[0][2][0] = 1;
        player_piece_positions[0][2][1] = 1;

        player_piece_positions[0][3][0] = 1;
        player_piece_positions[0][3][1] = 0;

        player_piece_positions[1][0][0] = 0;
        player_piece_positions[1][0][1] = 7;

        player_piece_positions[1][1][0] = 0;
        player_piece_positions[1][1][1] = 8;

        player_piece_positions[1][2][0] = 1;
        player_piece_positions[1][2][1] = 8;

        player_piece_positions[1][3][0] = 1;
        player_piece_positions[1][3][1] = 7;

    }

    if (num_players >= 3)
    {
        strncpy(board[7][0], all_pieces[2][0], 20);
        strncpy(board[7][1], all_pieces[2][1], 20);
        strncpy(board[8][0], all_pieces[2][3], 20);
        strncpy(board[8][1], all_pieces[2][2], 20);

        player_piece_positions[2][0][0] = 7;
        player_piece_positions[2][0][1] = 0;

        player_piece_positions[2][1][0] = 7;
        player_piece_positions[2][1][1] = 1;

        player_piece_positions[2][2][0] = 8;
        player_piece_positions[2][2][1] = 1;

        player_piece_positions[2][3][0] = 8;
        player_piece_positions[2][3][1] = 0;
    }

    if (num_players == 4)
    {
        strncpy(board[7][7], all_pieces[3][0], 20);
        strncpy(board[7][8], all_pieces[3][1], 20);
        strncpy(board[8][7], all_pieces[3][3], 20);
        strncpy(board[8][8], all_pieces[3][2], 20);

        player_piece_positions[3][0][0] = 7;
        player_piece_positions[3][0][1] = 7;

        player_piece_positions[3][1][0] = 7;
        player_piece_positions[3][1][1] = 8;

        player_piece_positions[3][2][0] = 8;
        player_piece_positions[3][2][1] = 8;

        player_piece_positions[3][3][0] = 8;
        player_piece_positions[3][3][1] = 7;
    }
}

int process_player_hand(int dice, 
                            int player_id,
                            int num_players, 
                            int player_pieces_positions[][4][2], 
                            int player_pieces_positions_indices[][4], 
                            int player_paths[][35][2],
                            int castle_positions[][4][2],
                            char board[9][9][20],
                            char default_board[9][9][20],
                            char P[],
                            char piece_names[][4][20],
                            char board_cell_castle_names[][4][20],
                            char board_cell_home_names[][4][20])
{

    /*
        MOVING THE PIECES OF A PLAYER ACCORDING TO
        HIS/HER CHOICES WHILE TAKING ACCOUNT THE GAME RULES
    */


    int choice = -1;
    char choices[4][100];
    int choices_count = 0;
    int action_happened = 0;
    int choice_index_to_piece[4];


    // Defining 4 choices for each piece. Remove from castle or move along the path
    for (int i = 0; i < 4; i++)
    {
        int position_index = player_pieces_positions_indices[player_id][i];
        
        if (position_index < 31)
        {
            if (position_index == -1)
            {
                if (dice == 6)
                {
                    snprintf(choices[choices_count], 100, "%d: PLACE PIECE %d TO BOARD", choices_count + 1, i + 1);
                    choice_index_to_piece[choices_count] = i;
                    choices_count++;
                }
            } else 
            {
                snprintf(choices[choices_count], 100, "%d: MOVE PIECE %d BY %d STEPS", choices_count + 1, i + 1, dice);
                choice_index_to_piece[choices_count] = i;
                choices_count++;
            }
        }    
    }

    // If no choices are defined, then we continue with the next player
    if (choices_count == 0)
    {
        printf("\nTHERE ARE NO MOVES FOR THIS PLAYER. NEXT PLAYER'S TURN...");
    } else
    {
        printf("\nCHOICES FOR PLAYER %d: \n", player_id + 1);
        for (int i = 0; i < choices_count; i++)
        {
            printf("%s\n", choices[i]);
        }

        // Ask until the player selects a valid choice
        while (choice < 1 || choice > choices_count)
        {
            printf("\nPLEASE SELECT AN APPROPRIATE OPTION: ");
            scanf("%d", &choice);
        }

        int piece_number = choice_index_to_piece[choice - 1];
        printf("%d", piece_number);

        // Retrieving current piece's position information
        int choice_x = player_pieces_positions[player_id][piece_number][0];
        int choice_y = player_pieces_positions[player_id][piece_number][1];
        int position_index = player_pieces_positions_indices[player_id][piece_number];

        // If player is in castle
        if (position_index == -1)
        {
            // Starting position
            int first_pos_x = player_paths[player_id][0][0];
            int first_pos_y = player_paths[player_id][0][1];

            // Check if there is another piece in the starting position
            if (strcmp(board[first_pos_x][first_pos_y], P) == 0)
            {
                // Placing the piece into the starting position and updating its position information
                strncpy(board[first_pos_x][first_pos_y], piece_names[player_id][piece_number], 20);
                strncpy(board[choice_x][choice_y], default_board[choice_x][choice_y], 20);
                player_pieces_positions[player_id][piece_number][0] = first_pos_x;
                player_pieces_positions[player_id][piece_number][1] = first_pos_y;
                player_pieces_positions_indices[player_id][piece_number] = 0;
                printf("\nPIECE IS PLACED INTO THE BOARD");
                action_happened = 1;
            } else
            {
                printf("\nTHIS PIECE CANNOT BE PLACED INTO THE BOARD BECAUSE THERE IS ANOTHER PIECE IN THE STARTING POSITION");
            }
            
        } else
        {
            int current_pos_index = player_pieces_positions_indices[player_id][piece_number];
            int dest_pos_index = current_pos_index + dice;
            
            // Check if piece has reached home
            if (current_pos_index >= 31)
            {
                printf("\nTHIS PIECE HAS ALREADY REACHED HOME");
            } else if (dest_pos_index >= 35)
            {
                // If the destination index exceeds the piece's path
                printf("\nTHIS PIECE CANNOT MOVE %d CELLS FORWARD", dice);
            } else
            {   
                // Candidate destination position
                int candidate_x = player_paths[player_id][dest_pos_index][0];
                int candidate_y = player_paths[player_id][dest_pos_index][1];

                int is_playable = 1;

                // Check if there is another piece of the same player in the destination
                if (strcmp(board[candidate_x][candidate_y], P) != 0)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (strcmp(board[candidate_x][candidate_y], piece_names[player_id][j]) == 0)
                        {
                            is_playable = 0;
                            break;
                        }
                    }
                }

                if (is_playable)
                {

                    // Check if there are another player's piece on the destination
                    // If there are, then remove it from that cell and place it back into its castle
                    char old_cell_value[20];
                    strncpy(old_cell_value, board[candidate_x][candidate_y], 20);
                    int move_piece = 1;
                    int dest_piece_found = 0;
                    for (int i = 0; i < num_players; i++)
                    {
                        if (dest_piece_found) {
                            break;
                        }

                        if (i != player_id)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                if (strcmp(old_cell_value, piece_names[i][j]) == 0)
                                {
                                    dest_piece_found = 1;
                                    player_pieces_positions[i][j][0] = castle_positions[i][j][0];
                                    player_pieces_positions[i][j][1] = castle_positions[i][j][1];
                                    if (player_pieces_positions_indices[i][j] < 31)
                                    {
                                        player_pieces_positions_indices[i][j] = -1;
                                        strncpy(board[player_pieces_positions[i][j][0]][player_pieces_positions[i][j][1]], old_cell_value, 20);
                                        printf("\n%s SHOULD RETURN TO ITS CASTLE", old_cell_value);
                                    } else {
                                        move_piece = 0;
                                    }
                                    break;
                                }
                            }
                        }
                    }

                    
                    if (move_piece)
                    {
                        // Place the piece on the destination point
                        strncpy(board[candidate_x][candidate_y], piece_names[player_id][piece_number], 20);
                        strncpy(board[choice_x][choice_y], default_board[choice_x][choice_y], 20);
                        player_pieces_positions[player_id][piece_number][0] = candidate_x;
                        player_pieces_positions[player_id][piece_number][1] = candidate_y;
                        player_pieces_positions_indices[player_id][piece_number] = dest_pos_index;
                        printf("\n%s HAS MOVED BY %d STEPS", piece_names[player_id][piece_number],dice);
                        action_happened = 1;
                    } else {
                        printf("\nPIECE IS NOT PLAYABLE BECAUSE THE PIECE IN THE DESTINATION HAS REACHED ITS HOME");
                    }

                } else
                {
                    printf("\nPIECE IS NOT PLAYABLE BECAUSE THERE IS ANOTHER PIECE OF THE PLAYER IN THE DESTINATION");
                }
            }
            
        }
        
    }

    return action_happened;

}


int check_player_win(int player_id, int player_piece_positions_indices[][4])
{
    int player_won = 1;

    for (int i = 0; i < 4; i++)
    {
        // If any one of the pieces are not in the castle
        if (player_piece_positions_indices[player_id][i] < 31)
        {
            player_won = 0;
            break;
        }
    }

    return player_won;
}

int check_game_over(int player_piece_positions_indices[][4])
{

    /*
        CHECKS FOR EVERY PLAYER IF THE PLAYER HAS WON AND
        RETURNS THE WINNING PLAYERS INDEX, RETURNS -1 OTHERWISE
    */

    int winning_player = -1;

    for (int i = 0; i < 4; i++)
    {
        if (check_player_win(i, player_piece_positions_indices))
        {
            winning_player = i;
            break;
        }
    }

    return winning_player;
}

int main()
{
    // Seeding the random number generator
    srand(time(NULL));

    int num_players;
    char colors[][7] = { "Yellow", "Red", "Green", "Blue" };
    // Defining constant chars for board cells

    // Piece names of players. These will be printed on the board
    char player_piece_names[][4][20] = {
        { "  PY1  ", "  PY2  ", "  PY3  ", "  PY4  " },
        { "  PR1  ", "  PR2  ", "  PR3  ", "  PR4  " },
        { "  PG1  ", "  PG2  ", "  PG3  ", "  PG4  " },
        { "  PB1  ", "  PB2  ", "  PB3  ", "  PB4  " }
    };

    // Piece paths for every player. Values are x-y coordinates
    int player_paths[][35][2] = {
        {{3, 0}, {3, 1}, {3, 2}, {3, 3}, {2, 3}, {1, 3}, {0, 3}, {0, 4}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {3, 6}, {3, 7}, {3, 8},
        {4, 8}, {5, 8}, {5, 7}, {5, 7}, {5, 5}, {6, 5}, {7, 5}, {8, 5}, {8, 4}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {5, 2}, {5, 1},
        {5, 0}, {4, 0}, {4, 1}, {4, 2}, {4, 3}},
        {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {3, 6}, {3, 7}, {3, 8}, {4, 8}, {5, 8}, {5, 7}, {5, 6}, {5, 5}, {6, 5}, {7, 5}, {8, 5},
        {8, 4}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {5, 2}, {5, 1}, {5, 0}, {4, 0}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {2, 3}, {1, 3},
        {0, 3}, {0, 4}, {1, 4}, {2, 4}, {3, 4}},
        {{8, 3}, {7, 3}, {6, 3}, {5, 3}, {5, 2}, {5,1}, {5, 0}, {4, 0}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {2, 3}, {1, 3}, {0, 3},
        {0, 4}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {3, 6}, {3, 7}, {3, 8}, {4, 8}, {5, 8}, {5, 7}, {5, 6}, {5, 5}, {6, 5}, {7, 5},
        {8, 5}, {8, 4}, {7, 4}, {6, 4}, {5, 4}},
        {{5, 8}, {5, 7}, {5, 6}, {5, 5}, {6, 5}, {7, 5}, {8, 5}, {8, 4}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {5, 2}, {5, 1}, {5, 0},
        {4, 0}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {2, 3}, {1, 3}, {0, 3}, {0, 4}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {3, 6}, {3, 7},
        {3, 8}, {4, 8}, {4, 7}, {4, 6}, {4, 5}}
    };

    // Defining castle positions of every piece
    int castle_positions[][4][2] = {
        {{0, 0}, {0, 1}, {1, 1}, {1, 0}},
        {{0, 7}, {0, 8}, {1, 8}, {1, 7}},
        {{7, 0}, {7, 1}, {8, 1}, {8, 0}},
        {{7, 7}, {7, 8}, {8, 8}, {8, 7}},
    };

    
    // Cell names to indicate players castles
    char board_cell_castle_names[][4][20] = {
        {"  HY1  ", "  HY2  ", "  HY3  ", "  HY4  "},
        {"  HR1  ", "  HR2  ", "  HR3  ", "  HR4  "},
        {"  HG1  ", "  HG2  ", "  HG3  ", "  HG4  "},
        {"  HB1  " ,"  HB2  ", "  HB3  ", "  HB4  "}
    };

    // Cell names to indicate players homes
    char board_cell_home_names[][4][20] = {
        {"  DY1  ", "  DY2  ", "  DY3  "},
        {"  DR1  ", "  DR2  ", "  DR3  "},
        {"  DG1  ", "  DG2  ", "  DG3  "},
        {"  DB1  " ,"  DB2  ", "  DB3  "}
    };

    // Path symbol to indicate the paths that piece can take
    char P[20] = "   P   ";
    // Empty cell string
    char EMP[20] = "       ";

    char board[9][9][20]; // This is the main board of the game. Players will see this board
    char default_board[9][9][20]; // This is a board with default values. It is used to replace cell values with default values after moving a piece
    
    // Building the initial board
    build_board(board, P, EMP, board_cell_castle_names, board_cell_home_names);
    build_board(default_board, P, EMP, board_cell_castle_names, board_cell_home_names);


    // Ask the user for number of players
    num_players = ask_num_players();

    // We will store every piece's position information in these varibles
    int player_piece_positions[num_players][4][2];
    int player_piece_positions_indices[num_players][4];

    // We fill the indices with -1 to check if a piece is removed from its hom
    for (int i = 0; i < num_players; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            player_piece_positions_indices[i][j] = -1;
        }
    }

    printf("Number of players is: %d\n", num_players);
    printf("Players are:\n");

    for (int i = 0; i < num_players; i++)
    {
        printf("Player %d: ", i + 1);
        printf("%s\n", colors[i]);
    }
    printf("\n");

    wait();

    printf("\nINITIAL EMPTY BOARD:\n");
    print_board(board);


    wait();

    printf("\nPIECES ARE PLACED IN THEIR CASTLES:\n");
    place_initial_pieces(board, player_piece_positions, num_players, player_piece_names);
    print_board(board);

    wait();

    int playing_order[num_players];
    printf("PLAYERS ROLL DICE FOR DETERMINING THE PLAYING ORDER:\n");
    determine_play_order(num_players, playing_order);

    wait();

    printf("PLAYING ORDER:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("Player %d: %s\n", playing_order[i] + 1, colors[playing_order[i]]);
    }

    printf("GAME NOW BEGINS:\n");

    int winning_player = -1;
    while (1)
    {
        for (int i = 0; i < num_players; i++)
        {
            int player_id = playing_order[i];
            int dice = roll_dice();

            printf("PLAYER %d ROLLS THE DICE...\n", player_id + 1);
            printf("RESULT IS: %d\n", dice);

            int action_happened = process_player_hand(
                                    dice, 
                                    player_id, 
                                    num_players,
                                    player_piece_positions, 
                                    player_piece_positions_indices, 
                                    player_paths, 
                                    castle_positions,
                                    board,
                                    default_board, 
                                    P, 
                                    player_piece_names, 
                                    board_cell_castle_names, 
                                    board_cell_home_names
                                );

            // If a piece has been moved
            if (action_happened)
            {
                print_board(board);
                // Checking winning situation after every move
                winning_player = check_game_over(player_piece_positions_indices);
                if (winning_player != -1)
                {
                    break;
                }
                
            }

            wait();
        }

        if (winning_player != -1)
        {
            break;
        }
    }

    printf("\n\n\n\n\nGAME IS OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nPLAYER %d: %s HAS WON\nCONGRULATIONS!!!!!!!!!!\n", winning_player + 1, colors[winning_player]);
    return 0;
}