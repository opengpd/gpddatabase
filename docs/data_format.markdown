# Data format

For the sake of simplicity and portability, the data files use the YAML data serialization format. YAML is an ASCII-based format where the structure of data is defined by indentation. Below is a dummy data file presenting all available features one can use when storing data in the database. The description of available keys is provided in a form of comments starting with '#' symbol.  

```yaml
---
# id (limited to 8 characters)
uuid: 9j7gof4d 

# metadata 
general_info:

   # date of insertion to database
   date: 2023-09-25
   # data type (enum) 
   data_type: DVCS 
   # tag to distinguish between data and pseudo-data (e.g. Monte Carlo study)
   # (optional) if not set pseudodata = false
   pseudodata: true 
   # collaboration name releasing data stored (limited to 20 characters)
   collaboration: "Example" 
   # reference, (limited to 60 characters)
   reference: "arXiv:01/02" 
   # experimental or lattice-QCD conditions
   conditions: 
      # lepton beam type (enum)
      lepton_beam_type: e- 
      # lepton beam energy (by default in GeV)
      lepton_beam_energy: 10. 
      # hadron beam type (enum)
      hadron_beam_type: p 
      # hadron beam energy (by default in GeV)
      # if missing, fixed target assumed
      hadron_beam_energy: 100. 
   # comment (optional, limited to 255 characters)
   comment: "Comment" 

# data
data:

    # a single data set (more than one can be defined in a single datafile)
    - data_set: 

        # label of current data set
        # limited to 20 characters 
        label: "Q2_dep" 
   
        # data related to kinematics
        kinematics: 

            # definition of kinematic phase-space, 
            # here 2D (xB, Q2) domain (enums)
            name: [xB, Q2] 
            # units (enums)
            unit: [none, GeV2] 
            # mean values of xB and Q2 obtained in three kinematic bins 
            value: 
                - [0.2, 1.5] # 1st bin: xB = 0.2, Q2/GeV2 = 1.5 
                - [0.3, 2.2] # ...
                - [0.4, 3.1] # 3th bin: xB = 0.4, Q2/GeV2 = 3.1 
            # or alternatively: 
            # value: [[0.2, 1], [0.3, 2], [0.4, 3]]

            # uncertainties associated to the mean values (optional)
            unc: 
                - [0.0015, 0.016] # 1st bin: xB = 0.2 +- 0.0015, Q2/GeV2 = 1.5 +- 0.016 
                - [0.0012, 0.011] # ...
                - [0.0019, 0.013] # 3th bin: xB = 0.4 +- 0.0019, Q2/GeV2 = 3.1 +- 0.013
            # bin boundaries (optional)
            bin: 
                - [[0.11, 0.25], [1, 2]] # 1st bin: 0.11 < xB < 0.25 and 1 < Q2/GeV2 < 2
                - [[0.25, 0.35], [2, 3]] # ...
                - [[0.35, 0.52], [3, 4]] # 1st bin: 0.35 < xB < 0.52 and 3 < Q2/GeV2 < 4
            # values obtained from replicas used in the related analysis (optional)
            # in the first bin three replicas give: 
            # xB = {0.2005, 0.1967, 0.1995} and Q2 = {1.514, 1.502, 1.487} 
            # the same replicas in the second bin give:
            # xB = {0.2997, 0.3005, 0.2988} and Q2 = {2.212, 2.193, 2.207} 
            replica: 
                - [[0.2005, 0.1967, 0.1995], [1.514, 1.502, 1.487]] 
                - [[0.2997, 0.3005, 0.2988], [2.212, 2.193, 2.207]]
                - [[0.4002, 0.4003, 0.3987], [3.094, 3.094, 3.107]]

        # data related to observables
        observable: 

            # definition of observables (enums)
            # here, in each kinematic bin experiment measures two observables: 
            # ALU and ALL asymmetries 
            name: [ALU, ALL]
            # units (enums)
            unit: [none, none]
            # mean values of ALU and ALL obtained in three kinematic bins
            value: 
                - [0.13, 0.29] # 1st bin: ALU = 0.13, ALL = 0.29
                - [0.14, 0.24] # ...
                - [0.11, 0.26] # 3th bin: ALU = 0.11, ALL = 0.26
            # statistical uncertainties associated to the mean values (optional)
            stat_unc: 
                - [0.03, 0.08] # 1st bin: ALU = 0.13 +- 0.03, ALL = 0.29 +- 0.08
                - [0.04, 0.07] # ...
                - [0.03, 0.02] # 3th bin: ALU = 0.11 +- 0.03, ALL = 0.26 +- 0.02
            # systematic uncertainties associated to the mean values (optional)
            # here we demonstrate how one can use asymmetric uncertainties 
            # and can specify a correlation between uncertainties
            sys_unc: 
                - [0.02, 0.01] # 1st bin: ALU = 0.13 +- 0.02, ALL = 0.29 +- 0.01
                - [0.01, [0.02, 0.03]] # 2nd bin: ALU = 0.14 +- 0.01, ALL = 0.24 - 0.02 + 0.03
                - ["corr_matrix1", 0.01, 0.02] # 3th bin: ALU = 0.11 +- 0.01, ALL = 0.26 +- 0.02, 
                                               # uncertainties are correlated according to 
                                               # 'corr_matrix1' matrix, see 'correlation' section
            # labels of contributions to systematic 
            # uncertainties (optional)
            # limited to 20 characters 
            sys_unc_contrib_label: ["fit", "detector"] 
            # contributions to systematic uncertainties (optional)
            sys_unc_contrib: 
                - [[0.015, 0.013], [0.007, 0.007]] # contributions to systematic uncertainties of 
                                                   # asymmetries measured in the first bin, 
                                                   # i.e. 0.02 and 0.01 values (see above)
                                                   # contributions are:
                                                   # 0.015 and 0.007 for source labeled as 'fit'
                                                   # 0.013 and 0.007 for source labeled as 'detector'
                - [[0.007, 0.008], [[0.010, 0.017], [0.020, 0.023]]] # use of asymmetric uncertainties 
                - ["corr_matrix2", 0.005, 0.008, 0.014, 0.016] # use of correlation matrix with elements:
                                                                   # sigma_sys_ALU_fit 
                                                                   # sigma_sys_ALU_detector
                                                                   # sigma_sys_ALL_fit 
                                                                   # sigma_sys_ALL_detector
            # values obtained from replicas used in the related analysis (optional)
            # in the first bin three replicas give: 
            # ALU = {0.132, 0.127, 0.140} and ALL = {0.295, 0.237, 0.327} 
            # the same replicas in the second bin give
            # ALU = {0.137, 0.149, 0.105} and ALL = {0.183, 0.232, 0.306} 
            replica: 
                - [[0.132, 0.127, 0.140], [0.295, 0.237, 0.327]] 
                - [[0.137, 0.149, 0.105], [0.183, 0.232, 0.306]]
                - [[0.097, 0.113, 0.120], [0.259, 0.262, 0.259]]
            # normalisation uncertainties (optional)
            # ALU +- 0.001, ALL +- 0.002 (for each kinematic bin)
            norm_unc: [0.001, 0.002] 
            # labels of contributions to 
            # systematic uncertainties (optional)
            # limited to 20 characters 
            norm_unc_contrib_label: ["target_pol", "beam_pol"] 
            # contributions to systematic
            # uncertainties (optional)
            # contributions are: 
            # 0.0006 and 0.0014 for source labeled as 'target_pol'
            # 0.0008 and 0.0019 for source labeled as 'beam_pol'
            norm_unc_contrib: [[0, 0.001], [0.0014, 0.0019]] 

#definition of correlation matrices used in data file
correlation: 

    - ["corr_matrix1", 1, 0.2, 0.2, 1] # 2D matrix labeled as 'corr_matrix1', 
                                       # with row-by-row values ((1,0.2),(0.2,1))
    - ["corr_matrix2", 1, 0.1, 0.3, 0.2, 0.1, 1, 0.5, 0.1, 0.3, 0.5, 1, -0.2, 0.2, 0.1, -0.2, 1] # 4D matrix
```

Data files are made out of three to four sections (`correlation` section is optional):

- `uuid`: data file identifier
- `general_info`: general information about data stored (metadata)
- `data`: data stored
- `correlation`: definition of correlation matrices used throughout `data` section

A single data file can store multiple data sets via `data_set` subsections, each one containing:

- `label`: data set label
- `kinematics`: kinematics stored
- `observable`: observables stored

The presented data file defines just one data set labelled `Q2_dep`. The stored data are `ALU` and `ALL` asymmetries measured in 2D bins of `xB` and `Q2`. Three kinematics points are defined with the following values of observables, statistical, systematic and normalisation uncertainties:

| $$x_B$$ | $$Q^2 / \mathrm{GeV}^2$$ | $$A_{\mathrm{LU}} \pm \sigma_{\mathrm{stat}} \pm \sigma_{\mathrm{sys}} \pm \sigma_{\mathrm{norm}}$$ | $$A_{\mathrm{LL}} \pm \sigma_{\mathrm{stat}} \pm \sigma_{\mathrm{sys}} \pm \sigma_{\mathrm{norm}}$$ |
|----|-------------|-----|-----|
$$0.2$$ | $$1.5$$ | $$0.13 \pm 0.03 \pm 0.02 \pm 0.001$$ | $$0.29 \pm 0.08 \pm 0.01 \pm 0.002$$ |
$$0.3$$ | $$2.2$$ | $$0.14 \pm 0.04 \pm 0.01 \pm 0.001$$ | $$0.24 \pm 0.07 \pm _{-0.02}^{+0.03} \pm 0.002$$ |
$$0.4$$ | $$3.1$$ | $$0.11 \pm 0.03 \pm 0.01^{*} \pm 0.001$$ | $$0.26 \pm 0.02 \pm 0.02^{*} \pm 0.002$$ |

In our example, all statistical uncertainties are symmetric. Systematic uncertainties, on the other hand, are symmetric only for the first point. For the second point, one of the uncertainties is asymmetric, while for the third point, the uncertainties are correlated according to `corr_1` correlation matrix defined in the `correlation` section of the data file.

Additional information is available. For kinematics, we have a definition of bins (the bin key). For instance, observables measured at the first point were extracted in the following 2D bin: $$0.11 < x_B < 0.25$$ and $$1~\mathrm{GeV}^2 < Q^2 < 2~\mathrm{GeV}^2$$. Additionally, information about the values given by replicas used in the analysis is available via the replica key. In our example, the first replica in the first bin gives $$\{x_{B} = 0.2005, Q^{2} = 1.514~\mathrm{GeV}^2\}$$, the second $$\{x_{B} = 0.1967, Q^{2} = 1.502~\mathrm{GeV}^2\}$$, etc. For observables, in addition to the information provided by individual replicas, we may store information on various contributions to the uncertainties, distinguished by labels. For instance, as shown in the table above, the normalization uncertainty associated with all $$A_{\mathrm{LL}}$$ points is $$0.002$$. With additional information provided by the norm_unc_contrib key, we know that the contribution of beam polarization uncertainty to this value is $$0.0014$$, while the contribution of target polarization uncertainty is $$0.0019$$.
