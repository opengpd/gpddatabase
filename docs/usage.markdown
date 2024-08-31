# Data format and usage

## Data format overview

Here is a dummy data file presenting all available features of the used format:

```yaml
---
uuid: 9j7gof4d 

general_info:
   date: 2023-09-25
   data_type: DVCS 
   pseudodata: true     # optional, if not set pseudodata = false
   collaboration: xsdsdsd # limited to 20 characters
   reference: arXiv:01/02 # optional, limited to 60 characters
   conditions:
      lepton_beam_type: e
      lepton_beam_energy: 10.
      hadron_beam_type: p
      hadron_beam_energy: 100.
   comment: "This is a comment" #optional

data:

    - data_set:

        label: "Q2_dep"
   
        kinematics:
            name: [xB, Q2]
            unit: [none, MeV2]
            value: 
                - [0.2, 1]
                - [0.3, 2]
                - [0.4, 3]
            #or alternatively: 
            #value: [[0.2, 1], [0.3, 2], [0.4, 3]]

            unc: #optional
                - [0.01, 0.1] #symmetric uncertainty, but can also be asymmetric 
                                #and given by correlation matrix 
                                #(see 'observable' section)
                - [0.01, 0.1]
                - [0.01, 0.1]
            bin: #optional      #boundaries of [xB, Q2] bins: 
                                #[[xBmin, xBmax], [Q2min, Q2max]]
                - [[0.1, 0.3], [0, 2]]
                - [[0.2, 0.4], [1, 3]]
                - [[0.3, 0.5], [2, 4]]
            replica: #optional
                - [[0.1, 0.1, 0.2, 0.3], [1.11, 1.11, 1.21, 1.31]]
                - [[0.1, 0.1, 0.2, 0.3], [2.11, 2.11, 2.21, 2.31]]
                - [[0.1, 0.1, 0.2, 0.3], [3.11, 3.11, 3.21, 3.31]]

        observable:
            name: [ALU, ALL] #in each kinematic bin experiment measures two observables
            unit: [none, none]
            norm_unc: [0.01, 0.014] 
            norm_unc_contrib_label: ["target_pol", "beam_pol"]
            norm_unc_contrib: [[0, 0.01], [0.01, 0.01]]
            value: 
                - [0.1, 0.2]
                - [0.11, 0.21]
                - [0.12, 0.22]
            stat_unc: #optional
                - [0.1, 0.2] #symmetric and symmetric
                - [0.1, 0.2] #symmetric and asymmetric
                - [0.1, 0.2]
            sys_unc: #optional
                - [0.1, 0.1] #symmetric and symmetric
                - [0.1, [0.1, 0.2]] #symmetric and asymmetric
                - ["corr_matrix1", 0.1, 0.1] #cov. matrix
            sys_unc_contrib_label: ["fit", "detector"] #optional
            sys_unc_contrib: #optional
                - [[0.06, 0.02], [0.34, 0.2]]   # contribution to systematic unc., 
                                                #e.g. for the first point sys_fit = 0.06, 
                                                #sys_detector = 0.02
                - [[0.06, 0.02], [0.34, 0.2]]
                - [[0.06, 0.02], [0.34, 0.2]]
            replica: #optional
                - [[0.1, 0.1, 0.2, 0.3], [0.11, 0.11, 0.21, 0.31]]
                - [[0.1, 0.1, 0.2, 0.3], [0.11, 0.11, 0.21, 0.31]]
                - [[0.1, 0.1, 0.2, 0.3], [0.11, 0.11, 0.21, 0.31]]

correlation:
    - ["corr_matrix1", 1, 0.2, 0.2, 1]
    - ["corr_matrix2", 1, 0.4, 0.4, 1]
```

Data files are made out of three or four sections (`correlation` section is optional):

- `uuid`: data file identifier
- `general_info`: general information about data stored (metadata)
- `data`: data stored
- `correlation`: definition of correlation matrices used throughout `data` section

A single data file can store multiple data sets via `data_set` subsections, each one containing:

- `label`: data set label
- `kinematics`: kinematics stored
- `observable`: observables stored

The idea behind storing multiple data sets in a single data file is that experiments often use the same data to separately extract observables as functions of independent variables. For instance, in XXX HERMES reports the measurement of XX asymmetry in 1D bins of X, X or X, based on raw data obtained in the same experimental runs. Therefore, in this case, it makes sense to store three different data sets in a single data file. These data sets must be distinguished by unique labels, say `x`, `x` and `x`, such that users may unambiguously chose which data sets (here, kinematic dependencies) they want to use in their analyses.

The presented data file defines just one data set labelled `Q2_dep`. The stored data are `ALU` and `ALL` asymmetries measured in 2D bins of `xB` and `Q2`. Three kinematics points are defined with the following values of the measured observables:

| xB | Q2 \[GeV2\] | ALU | ALL |
|----|-----------|-----|-----|
| 0\.2 | 1 | 0\.1 \\pm 0.1 sigma_stat \\pm sigma_sys | 0\.2 |
| 0\.3 | 2 | 0\.11 | 0\.21 |
| 0\.4 | 3 | 0\.12 | 0\.22 |

In the above, we only showed the statistical uncertainties. Systematic uncertainties for the first point are `x` for `x` and `x` for `x`. For the second point, one of the uncertainties is asymmetric, we have `x` and `x`, retrospectively. For the third point, the uncertainties are `x` and `x`, and they are correlated according to `corr_1` correlation matrix defined in `correlation` section of the data file. Additionally to the statistical and systematic uncertainties, we also have information on normalization uncertainties, which are typically related to the polarization measurements. For a given observable, this type of uncertainty is common for all data points. In our example, the normalisation uncertainty is `x` for `ALU` and `x` for `ALL`.

In addition to this basic information presented so far, we have many additional information available.  For kinematic, we have definition of bins. For instance, observables measured in the first kinematic point were extracted in the following 2D bin: `0.1 < xB < 0.3 and 0 < Q2 < 2 GeV2`.

In e.g. lattice-QCD computations, the mean values of kinematic variables and related uncertainties are sometimes estimated from a set of replicas. Values given by these replicas can be stored in data files via `replica` tag. In our example, the first replica replica gives xB_0 = 0.1, Q2_0 = 3, the second xB_1=, etc. The last replica gives 0.23 and 2332.

For observables, in addition to the information provided by individual replicas, we may store information on various contributions to the uncertainties. These contributions are distinguished by labels. For instance, as we already know, the normalization uncertainty of all ALL values is `0.014`. With additional information provided by `norm_unc_contrib` tag, we know that the contribution of beam polarization uncertainty to this value is `0.01`, while the contribution of target polarisation uncertainty is `0.01`. For `ALU` only the beam polarisation uncertainty contributes.

## Loading data file

## General information

## Data points