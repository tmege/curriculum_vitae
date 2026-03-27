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

void	print_competencias(t_competencias *comp)
{
	if (!comp)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                          SKILLS                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	if (comp->lenguajes)
	{
		printf("Programming Languages:\n");
		print_skill_list(comp->lenguajes);
		printf("\n");
	}
	if (comp->herramientas)
	{
		printf("Tools / Frameworks:\n");
		print_skill_list(comp->herramientas);
		printf("\n");
	}
	if (comp->sistemas)
	{
		printf("Low-Level Skills:\n");
		print_skill_list(comp->sistemas);
		printf("\n");
	}
	if (comp->competencias_tecnicas)
	{
		printf("AI & Other Skills:\n");
		print_skill_list(comp->competencias_tecnicas);
		printf("\n");
	}
	if (comp->idiomas)
	{
		printf("Languages:\n");
		print_skill_list(comp->idiomas);
	}
}

void	print_proyectos(t_proyecto *proyectos)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                        PROJECTS                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (proyectos)
	{
		printf("▸ %s\n", proyectos->titulo);
		printf("  %s\n\n", proyectos->lugar);
		printf("  %s\n", proyectos->descripcion);

		if (proyectos->tecnologias)
		{
			printf("\n  Technologies:\n");
			print_skill_list(proyectos->tecnologias);
		}

		if (proyectos->next)
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		proyectos = proyectos->next;
	}
}

void	print_formacion(t_formacion *formacion)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                        EDUCATION                                 ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (formacion)
	{
		printf("▸ %s\n", formacion->titulo);
		printf("  %s, %s\n", formacion->institucion, formacion->ubicacion);
		printf("  %s - %s\n", formacion->fecha_inicio, formacion->fecha_fin);
		if (formacion->descripcion && strlen(formacion->descripcion) > 0)
			printf("  %s\n", formacion->descripcion);

		if (formacion->next)
			printf("\n");
		formacion = formacion->next;
	}
}

void	print_experiencia(t_experiencia *exp)
{
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                  PROFESSIONAL EXPERIENCE                         ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

	while (exp)
	{
		printf("▸ %s\n", exp->puesto);
		if (exp->ubicacion && strlen(exp->ubicacion) > 0)
			printf("  %s, %s\n", exp->empresa, exp->ubicacion);
		else
			printf("  %s\n", exp->empresa);
		printf("  %s - %s\n", exp->fecha_inicio, exp->fecha_fin);

		if (exp->responsabilidades)
		{
			printf("\n");
			print_skill_list(exp->responsabilidades);
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
	name_len = strlen(cv->nombre);
	pad_left = (width - name_len) / 2;
	pad_right = width - name_len - pad_left;
	printf("\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("██                                                                ██\n");
	printf("██");
	i = -1;
	while (++i < pad_left)
		printf(" ");
	printf("%s", cv->nombre);
	i = -1;
	while (++i < pad_right)
		printf(" ");
	printf("██\n");
	printf("██                                                                ██\n");
	printf("████████████████████████████████████████████████████████████████████\n");
	printf("\n");
	printf("  %s | %s | %s\n", cv->ubicacion, cv->email, cv->telefono);
	printf("  %s | %s\n", cv->github, cv->linkedin);
}

void	print_perfil(t_cv *cv)
{
	if (!cv)
		return ;
	printf("╔══════════════════════════════════════════════════════════════════╗\n");
	printf("║                         SUMMARY                                  ║\n");
	printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
	printf("%s\n", cv->perfil);
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
		print_perfil(cv);
	else if (choice == '2')
		print_competencias(cv->competencias);
	else if (choice == '3')
		print_proyectos(cv->proyectos);
	else if (choice == '4')
		print_formacion(cv->formacion);
	else if (choice == '5')
		print_experiencia(cv->experiencia);
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
