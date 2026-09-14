# Axial Force of a Double Circular-Arc Helical Gear Pump (CFD)

Course project for *Fluid Mechanics & Hydraulics* (Tongji University, 2025).

Gear pumps are increasingly used as the power element of **electro-hydrostatic actuators
(EHA)** in aerospace actuation, where they run at high pressure and high speed. A
conventional involute spur gear suffers from trapped-oil effects, radial imbalance, flow
pulsation and noise. Replacing it with a **double circular-arc helical** profile improves
meshing smoothness and reduces pulsation.

Operating point studied: **25 MPa**, **70 L/min**, **10 000 rpm**, −55 °C … +205 °C.

## What was done

1. **Tooth profile design** — an "arc–involute–arc" curve was selected and its parametric
   equations derived, then the gear parameters (module, helix angle, contact ratio) were
   chosen and the displacement verified.
2. **Modelling** — 2D and 3D models of the gear pair built in SolidWorks.
3. **CFD** — mesh generation and steady-state simulation in ANSYS Fluent; the outlet
   pressure field was extracted and correlated with the resulting **axial force** on the
   gears.
4. **Speed sweep** — repeated runs at different rotational speeds to characterise how
   axial force varies with speed.

## Layout

| Path | Contents |
| --- | --- |
| `report_axial_force_gear_pump.docx`, `slides_axial_force_gear_pump.pptx` | Full report and presentation (Chinese) |
| `literature_review.docx` | Literature review |
| `cad/` | SolidWorks parts and assembly of the pump |
| `simulation/2d/case/2d.cas.h5` | 2D Fluent case |
| `simulation/2d/fluid_domain/2d.agdb` | 2D fluid-domain geometry |
| `simulation/2d/mesh/2d.msh` | 2D mesh |
| `simulation/2d/boundary_udf/cilun.c` | Boundary-condition UDF for the 2D case |
| `simulation/3d/3d.cas.h5`, `3d.msh.h5`, `3d.scdoc` | 3D case, mesh and SpaceClaim geometry |
| `simulation/axial_force/` | Axial-force case and data, `pressure_vs_period.xlsx`, `time_parameters.docx`, `simulation_video.mp4` |
| `simulation/speed_sweep/` | Speed-sweep case/data and `speed_sweep_data.xlsx` |
| `simulation/boundary_udf/`, `simulation/3d/cilun.c` | Further copies of the same UDF |

## Reproducing

Open the relevant `.cas.h5` in ANSYS Fluent, point the UDF (`cilun.c`) at the correct
boundary, and initialise from the matching `.dat.h5` if you want to restart from a
converged state instead of running from scratch.

## Notes

- `cad/` and `simulation/cad_copy/` contain the **same ten SolidWorks files** — one copy
  is redundant.
- `cilun.c` appears in three places (2D, 3D and the standalone `boundary_udf/` folder).
- The `.h5` case/data files are large (≈11–28 MB each) and are the bulk of this folder
  (≈109 MB). Consider Git LFS, or exclude them, if repository size matters.
- The filenames inside `cad/` are still Chinese (`圆弧齿轮1.SLDPRT`, `泵壳体.SLDPRT`, …).
  They were deliberately left alone: SolidWorks assemblies reference parts **by
  filename**, so renaming them here would break `装配体1.SLDASM`.
