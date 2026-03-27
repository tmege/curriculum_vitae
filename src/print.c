#include "cv.h"

/* ========== PRINT HELPERS ========== */

static void	print_skill_list(t_skill *skills)
{
	while (skills)
	{
		printf("  • %s\n", skills->name);
		skills = skills->next;
	}
}

static void	print_separator(void)
{
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

/* ========== PRINT FUNCTIONS ========== */

void	print_competencies(t_competencies *comp)
{
	if (!comp)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                          SKILLS                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	if (comp->languages)
	{
		printf("Programming Languages:\n");
		print_skill_list(comp->languages);
		printf("\n");
	}
	if (comp->tools)
	{
		printf("Tools / Frameworks:\n");
		print_skill_list(comp->tools);
		printf("\n");
	}
	if (comp->systems)
	{
		printf("Low-Level Skills:\n");
		print_skill_list(comp->systems);
		printf("\n");
	}
	if (comp->technical_skills)
	{
		printf("AI & Other Skills:\n");
		print_skill_list(comp->technical_skills);
		printf("\n");
	}
	if (comp->spoken_languages)
	{
		printf("Languages:\n");
		print_skill_list(comp->spoken_languages);
	}
}

void	print_projects(t_project *projects)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                        PROJECTS                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (projects)
	{
		printf("▸ %s\n", projects->title);
		printf("  %s\n\n", projects->location);
		printf("  %s\n", projects->description);

		if (projects->technologies)
		{
			printf("\n  Technologies:\n");
			print_skill_list(projects->technologies);
		}

		if (projects->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		projects = projects->next;
	}
}

void	print_education(t_education *education)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                        EDUCATION                                 ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (education)
	{
		printf("▸ %s\n", education->title);
		printf("  %s, %s\n", education->institution, education->location);
		printf("  %s - %s\n", education->start_date, education->end_date);
		if (education->description && strlen(education->description) > 0)
			printf("  %s\n", education->description);

		if (education->next)
			printf("\n");
		education = education->next;
	}
}

void	print_experience(t_experience *exp)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                  PROFESSIONAL EXPERIENCE                         ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (exp)
	{
		printf("▸ %s\n", exp->position);
		if (exp->location && strlen(exp->location) > 0)
			printf("  %s, %s\n", exp->company, exp->location);
		else
			printf("  %s\n", exp->company);
		printf("  %s - %s\n", exp->start_date, exp->end_date);

		if (exp->responsibilities)
		{
			printf("\n");
			print_skill_list(exp->responsibilities);
		}

		if (exp->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		exp = exp->next;
	}
}

void	print_header(t_cv *cv)
{
	int	width;
	int	name_len;
	int	pad_left;
	int	pad_right;
	int	i;

	if (!cv)
		return ;
	width = 64;
	name_len = strlen(cv->name);
	pad_left = (width - name_len) / 2;
	pad_right = width - name_len - pad_left;
	printf("\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("██                                                                ██\n");
	printf("██");
	i = -1;
	while (++i < pad_left)
		printf(" ");
	printf("%s", cv->name);
	i = -1;
	while (++i < pad_right)
		printf(" ");
	printf("██\n");
	printf("██                                                                ██\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("\n");
	printf("  %s | %s | %s\n", cv->location, cv->email, cv->phone);
	printf("  %s | %s\n", cv->github, cv->linkedin);
}

void	print_profile(t_cv *cv)
{
	if (!cv)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                         SUMMARY                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	printf("%s\n", cv->profile);
}

static void	print_menu(void)
{
	printf("\n");
	print_separator();
	printf("  ┌─────────────────────────────────────────┐\n");
	printf("  │            SELECT A SECTION             │\n");
	printf("  ├─────────────────────────────────────────┤\n");
	printf("  │  [1]  Summary                           │\n");
	printf("  │  [2]  Skills                            │\n");
	printf("  │  [3]  Projects                          │\n");
	printf("  │  [4]  Education                         │\n");
	printf("  │  [5]  Professional Experience           │\n");
	printf("  │  [0]  Exit                              │\n");
	printf("  └─────────────────────────────────────────┘\n");
	printf("\n  > ");
}

static void	handle_choice(t_cv *cv, char choice)
{
	printf("\n");
	if (choice == '1')
		print_profile(cv);
	else if (choice == '2')
		print_competencies(cv->competencies);
	else if (choice == '3')
		print_projects(cv->projects);
	else if (choice == '4')
		print_education(cv->education);
	else if (choice == '5')
		print_experience(cv->experience);
	else if (choice != '0')
		printf("  Invalid option. Please try again.\n");
}

void	run_menu(t_cv *cv)
{
	char	buf[2];

	if (!cv)
		return ;
	print_header(cv);
	while (1)
	{
		print_menu();
		if (read(STDIN_FILENO, buf, 1) <= 0)
			break ;
		buf[1] = '\0';
		if (buf[0] == '0')
		{
			printf("\n  /* TODO: hire(this_candidate); */\n\n");
			break ;
		}
		if (buf[0] != '\n')
			handle_choice(cv, buf[0]);
		while (read(STDIN_FILENO, buf, 1) == 1 && buf[0] != '\n')
			;
	}
}
