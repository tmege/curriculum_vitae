#include "cv.h"

static void	populate_competencies(t_cv *cv)
{
	cv->competencies = competencies_init();

	// Programming Languages
	skill_add_back(&cv->competencies->languages, skill_new("C"));
	skill_add_back(&cv->competencies->languages, skill_new("Bash"));
	skill_add_back(&cv->competencies->languages, skill_new("C++ (basics)"));
	skill_add_back(&cv->competencies->languages, skill_new("Python (basics)"));

	// Tools / Frameworks
	skill_add_back(&cv->competencies->tools, skill_new("Linux"));
	skill_add_back(&cv->competencies->tools, skill_new("Docker"));
	skill_add_back(&cv->competencies->tools, skill_new("VirtualBox"));
	skill_add_back(&cv->competencies->tools, skill_new("Git/GitHub"));
	skill_add_back(&cv->competencies->tools, skill_new("Vim & NeoVim"));

	// Low-Level Skills
	skill_add_back(&cv->competencies->systems, skill_new("Parsing"));
	skill_add_back(&cv->competencies->systems, skill_new("Memory management"));
	skill_add_back(&cv->competencies->systems, skill_new("UNIX processes"));
	skill_add_back(&cv->competencies->systems, skill_new("Pipes & redirections"));
	skill_add_back(&cv->competencies->systems, skill_new("Debugging"));
	skill_add_back(&cv->competencies->systems, skill_new("Bash scripting"));

	// AI & Other Skills
	skill_add_back(&cv->competencies->technical_skills,
		skill_new("Task automations"));
	skill_add_back(&cv->competencies->technical_skills,
		skill_new("API integrations"));
	skill_add_back(&cv->competencies->technical_skills,
		skill_new("AI workflows & tool chaining"));
	skill_add_back(&cv->competencies->technical_skills,
		skill_new("Prompt engineering"));
	skill_add_back(&cv->competencies->technical_skills,
		skill_new("LLMs (Hugging Face, Anthropic APIs, n8n)"));

	// Languages
	skill_add_back(&cv->competencies->spoken_languages,
		skill_new("French (native)"));
	skill_add_back(&cv->competencies->spoken_languages,
		skill_new("English (fluent)"));
	skill_add_back(&cv->competencies->spoken_languages,
		skill_new("Spanish (fluent)"));
}

static void	populate_projects(t_cv *cv)
{
	t_project	*project;

	// 42 School Projects
	project = project_new(
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
	skill_add_back(&project->technologies, skill_new("C"));
	skill_add_back(&project->technologies, skill_new("Makefile"));
	skill_add_back(&project->technologies, skill_new("System calls"));
	skill_add_back(&project->technologies, skill_new("Algorithms"));
	add_project(cv, project);

	// AI News Aggregator
	project = project_new(
		"AI-Powered News Aggregator",
		"Personal project",
		"Built an AI-powered news aggregator integrated into Discord, using APIs\n"
		"  and LLMs to deliver daily technology updates automatically with a cron tab."
	);
	skill_add_back(&project->technologies, skill_new("APIs"));
	skill_add_back(&project->technologies, skill_new("LLMs"));
	skill_add_back(&project->technologies, skill_new("Discord"));
	skill_add_back(&project->technologies, skill_new("Cron"));
	add_project(cv, project);

	// Artist Dashboard
	project = project_new(
		"Artist Dashboard",
		"Personal project",
		"Developed an artist dashboard that retrieves data from social media and\n"
		"  streaming platforms via automated workflows, including OAuth authentication."
	);
	skill_add_back(&project->technologies, skill_new("APIs"));
	skill_add_back(&project->technologies, skill_new("OAuth"));
	skill_add_back(&project->technologies, skill_new("n8n"));
	add_project(cv, project);

	// Trading Bot Dashboard
	project = project_new(
		"Trading Bot Dashboard",
		"Personal project",
		"Built a trading bot dashboard combining market APIs and LLMs to retrieve\n"
		"  data and analyze market sentiment."
	);
	skill_add_back(&project->technologies, skill_new("Market APIs"));
	skill_add_back(&project->technologies, skill_new("LLMs"));
	add_project(cv, project);

	// Vocal Generation Tool
	project = project_new(
		"Vocal Generation Tool",
		"Personal project",
		"Built a vocal generation tool using local Hugging Face models."
	);
	skill_add_back(&project->technologies, skill_new("Hugging Face"));
	skill_add_back(&project->technologies, skill_new("Python"));
	add_project(cv, project);

	// Hardware Projects
	project = project_new(
		"Hardware Projects",
		"Personal projects",
		"Soldering, PCB component replacement, motherboard repair, console modding,\n"
		"  microphone/audio repair, cable fabrication, and low-voltage work."
	);
	add_project(cv, project);
}

static void	populate_education(t_cv *cv)
{
	t_education	*edu;

	// 42 Barcelona
	edu = education_new(
		"Computer Science Training",
		"42",
		"Barcelona",
		"March 2025",
		"Present",
		""
	);
	add_education(cv, edu);

	// Professional Electrician Certificate
	edu = education_new(
		"Professional Electrician Certificate",
		"L'Ecole Des Pros",
		"Paris",
		"Dec 2021",
		"June 2022",
		""
	);
	add_education(cv, edu);

	// Sound & Music Engineering
	edu = education_new(
		"Professional Certificate in Sound & Music Engineering",
		"RAC",
		"Montreal",
		"Jan 2018",
		"Jan 2019",
		""
	);
	add_education(cv, edu);

	// Biology
	edu = education_new(
		"Bachelor in Biology",
		"Universite de Montreal",
		"Montreal",
		"Sept 2014",
		"Dec 2017",
		""
	);
	add_education(cv, edu);
}

static void	populate_experience(t_cv *cv)
{
	t_experience	*exp;

	// Sound & Music Engineer
	exp = experience_new(
		"Sound & Music Engineer",
		"Studio 22, Barcelona & Studio Niel, Paris",
		"",
		"June 2019",
		"Mar 2025"
	);
	skill_add_back(&exp->responsibilities,
		skill_new("Recording, mixing and mastering in a professional studio environment"));
	add_experience(cv, exp);

	// Electrician
	exp = experience_new(
		"Electrician",
		"JP Sausset Electricite",
		"",
		"June 2022",
		"Dec 2022"
	);
	add_experience(cv, exp);
}

int	main(void)
{
	t_cv	*cv;

	cv = cv_init();
	if (!cv)
		return (1);

	// Personal info
	cv->name = strdup("TIMOTHEE PABLO MEGE");
	cv->location = strdup("Barcelona, Spain");
	cv->email = strdup("t.p.mege@gmail.com");
	cv->phone = strdup("+34613444715");
	cv->github = strdup("github.com/tmege");
	cv->linkedin = strdup("linkedin.com/in/t-mege");
	cv->profile = strdup(
		"Computer Science student at 42 Barcelona (60%% completed) with a strong interest\n"
		"in emerging technologies. Combining a systems programming background with\n"
		"hands-on experience in AI-powered automation, looking to put these skills to\n"
		"work in a professional environment while completing my training."
	);

	// Populate sections
	populate_competencies(cv);
	populate_projects(cv);
	populate_education(cv);
	populate_experience(cv);

	// Interactive menu
	run_menu(cv);

	// Free memory
	free_cv(cv);

	return (0);
}
