#include "player.h"
//http://stackoverflow.com/questions/20628099/parsing-yaml-to-values-with-libyaml-in-c
void getPlayerName()
{
	FILE * readYaml = fopen("../data/player/player.yaml", "r");
	yaml_parser_t parser;
	yaml_token_t token;

	if(!yaml_parser_initialize(&parser))
		fputs("Failed to initialize parser...", stderr);
	if(!readYaml)
		fputs("Failed to open file.", stderr);
	yaml_parser_set_input_file(&parser,readYaml);

	do
	{
		yaml_parser_scan(&parser, &token);
		switch(token.type)
		{
			case YAML_SCALAR_TOKEN: 
				strncpy(playerName, (char*)token.data.scalar.value, 20);
			break;
			default:
			break;
		}
	}while(token.type != YAML_STREAM_END_TOKEN);
	yaml_parser_delete(&parser);
	fclose(readYaml);
}
void buyUnit(player currPlayer)
{
		
}
