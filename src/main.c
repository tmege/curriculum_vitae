#include "cv.h"

static void	populate_competencias(t_cv *cv)
{
	cv->competencias = competencias_init();

	// Programming Languages
	skill_add_back(&cv->competencias->lenguajes, skill_new("C"));
	skill_add_back(&cv->competencias->lenguajes, skill_new("Bash"));
	skill_add_back(&cv->competencias->lenguajes, skill_new("C++ (basics)"));
	skill_add_back(&cv->competencias->lenguajes, skill_new("Python (basics)"));

	// Tools / Frameworks
	skill_add_back(&cv->competencias->herramientas, skill_new("Linux"));
	skill_add_back(&cv->competencias->herramientas, skill_new("Docker"));
	skill_add_back(&cv->competencias->herramientas, skill_new("VirtualBox"));
	skill_add_back(&cv->competencias->herramientas, skill_new("Git/GitHub"));
	skill_add_back(&cv->competencias->herramientas, skill_new("Vim & NeoVim"));

	// Low-Level Skills
	skill_add_back(&cv->competencias->sistemas, skill_new("Parsing"));
	skill_add_back(&cv->competencias->sistemas, skill_new("Memory management"));
	skill_add_back(&cv->competencias->sistemas, skill_new("UNIX processes"));
	skill_add_back(&cv->competencias->sistemas, skill_new("Pipes & redirections"));
	skill_add_back(&cv->competencias->sistemas, skill_new("Debugging"));
	skill_add_back(&cv->competencias->sistemas, skill_new("Bash scripting"));

	// AI & Other Skills
	skill_add_back(&cv->competencias->competencias_tecnicas,
		skill_new("Task automations"));
	skill_add_back(&cv->competencias->competencias_tecnicas,
		skill_new("API integrations"));
	skill_add_back(&cv->competencias->competencias_tecnicas,
		skill_new("AI workflows & tool chaining"));
	skill_add_back(&cv->competencias->competencias_tecnicas,
		skill_new("Prompt engineering"));
	skill_add_back(&cv->competencias->competencias_tecnicas,
		skill_new("LLMs (Hugging Face, Anthropic APIs, n8n)"));

	// Languages
	skill_add_back(&cv->competencias->idiomas, skill_new("French (native)"));
	skill_add_back(&cv->competencias->idiomas, skill_new("English (fluent)"));
	skill_add_back(&cv->competencias->idiomas, skill_new("Spanish (fluent)"));
}

static void	populate_proyectos(t_cv *cv)
{
	t_proyecto	*proyecto;

	// 42 School Projects
	proyecto = proyecto_new(
		"42 School C Projects",
		"42 Barcelona",
		"Intensive, low-level C projects consisting of memory, concurrency,\n"
		"  UNIX processes, and algorithms:\n"
		"  - MiniShell: parsing, pipes, redirections, command execution, memory mgmt\n"
		"  - Philosophers: concurrent programming with mutexes & deadlock prevention\n"
		"  - Pipex: recreation of UNIX pipelines\n"
		"  - Push_swap: algorithmic optimization\n"
		"  - So_long & cub3d: game logic, key loops, graphics & ray-casting\n"
		"  - Libft / Get_next_line: custom C library and buffer management\n"
		"  - NetPractice: TCP/IP networking, subnet config, IP addressing, routing"
	);
	skill_add_back(&proyecto->tecnologias, skill_new("C"));
	skill_add_back(&proyecto->tecnologias, skill_new("Makefile"));
	skill_add_back(&proyecto->tecnologias, skill_new("System calls"));
	skill_add_back(&proyecto->tecnologias, skill_new("Algorithms"));
	add_proyecto(cv, proyecto);

	// AI News Aggregator
	proyecto = proyecto_new(
		"AI-Powered News Aggregator",
		"Personal project",
		"Built an AI-powered news aggregator integrated into Discord, using APIs\n"
		"  and LLMs to deliver daily technology updates automatically with a cron tab."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("APIs"));
	skill_add_back(&proyecto->tecnologias, skill_new("LLMs"));
	skill_add_back(&proyecto->tecnologias, skill_new("Discord"));
	skill_add_back(&proyecto->tecnologias, skill_new("Cron"));
	add_proyecto(cv, proyecto);

	// Artist Dashboard
	proyecto = proyecto_new(
		"Artist Dashboard",
		"Personal project",
		"Developed an artist dashboard that retrieves data from social media and\n"
		"  streaming platforms via automated workflows, including OAuth authentication."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("APIs"));
	skill_add_back(&proyecto->tecnologias, skill_new("OAuth"));
	skill_add_back(&proyecto->tecnologias, skill_new("n8n"));
	add_proyecto(cv, proyecto);

	// Trading Bot Dashboard
	proyecto = proyecto_new(
		"Trading Bot Dashboard",
		"Personal project",
		"Built a trading bot dashboard combining market APIs and LLMs to retrieve\n"
		"  data and analyze market sentiment."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("Market APIs"));
	skill_add_back(&proyecto->tecnologias, skill_new("LLMs"));
	add_proyecto(cv, proyecto);

	// Vocal Generation Tool
	proyecto = proyecto_new(
		"Vocal Generation Tool",
		"Personal project",
		"Built a vocal generation tool using local Hugging Face models."
	);
	skill_add_back(&proyecto->tecnologias, skill_new("Hugging Face"));
	skill_add_back(&proyecto->tecnologias, skill_new("Python"));
	add_proyecto(cv, proyecto);

	// Hardware Projects
	proyecto = proyecto_new(
		"Hardware Projects",
		"Personal projects",
		"Soldering, PCB component replacement, motherboard repair, console modding,\n"
		"  microphone/audio repair, cable fabrication, and low-voltage work."
	);
	add_proyecto(cv, proyecto);
}

static void	populate_formacion(t_cv *cv)
{
	t_formacion	*form;

	// 42 Barcelona
	form = formacion_new(
		"Computer Science Training",
		"42",
		"Barcelona",
		"March 2025",
		"Present",
		""
	);
	add_formacion(cv, form);

	// Professional Electrician Certificate
	form = formacion_new(
		"Professional Electrician Certificate",
		"L'Ecole Des Pros",
		"Paris",
		"Dec 2021",
		"June 2022",
		""
	);
	add_formacion(cv, form);

	// Sound & Music Engineering
	form = formacion_new(
		"Professional Certificate in Sound & Music Engineering",
		"RAC",
		"Montreal",
		"Jan 2018",
		"Jan 2019",
		""
	);
	add_formacion(cv, form);

	// Biology
	form = formacion_new(
		"Bachelor in Biology",
		"Universite de Montreal",
		"Montreal",
		"Sept 2014",
		"Dec 2017",
		""
	);
	add_formacion(cv, form);
}

static void	populate_experiencia(t_cv *cv)
{
	t_experiencia	*exp;

	// Sound & Music Engineer
	exp = experiencia_new(
		"Sound & Music Engineer",
		"Studio 22, Barcelona & Studio Niel, Paris",
		"",
		"June 2019",
		"Mar 2025"
	);
	skill_add_back(&exp->responsabilidades,
		skill_new("Recording, mixing and mastering in a professional studio environment"));
	add_experiencia(cv, exp);

	// Electrician
	exp = experiencia_new(
		"Electrician",
		"JP Sausset Electricite",
		"",
		"June 2022",
		"Dec 2022"
	);
	add_experiencia(cv, exp);
}

int	main(void)
{
	t_cv	*cv;
	
	cv = cv_init();
	if (!cv)
		return (1);
	
	// Personal info
	cv->nombre = strdup("TIMOTHEE PABLO MEGE");
	cv->ubicacion = strdup("Barcelona, Spain");
	cv->email = strdup("t.p.mege@gmail.com");
	cv->telefono = strdup("+34613444715");
	cv->github = strdup("github.com/tmege");
	cv->linkedin = strdup("linkedin.com/in/t-mege");
	cv->perfil = strdup(
		"Computer Science student at 42 Barcelona (60%% completed) with a strong interest\n"
		"in emerging technologies. Combining a systems programming background with\n"
		"hands-on experience in AI-powered automation, looking to put these skills to\n"
		"work in a professional environment while completing my training."
	);
	
	// Poblar secciones
	populate_competencias(cv);
	populate_proyectos(cv);
	populate_formacion(cv);
	populate_experiencia(cv);
	
	// Menu interactivo
	run_menu(cv);
	
	// Liberar memoria
	free_cv(cv);
	
	return (0);
}
