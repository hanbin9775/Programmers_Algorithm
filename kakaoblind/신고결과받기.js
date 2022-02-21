function solution(id_list, report, k) {
  const reportStacks = {};
  id_list.forEach((id) => {
    reportStacks[id] = [];
  });
  const emailStacks = {};
  id_list.forEach((id) => {
    emailStacks[id] = 0;
  });
  const validatedReport = [...new Set(report)];

  // stack report
  validatedReport.forEach((item) => {
    const [reporter, respondent] = item.split(" ");
    reportStacks[respondent].push(reporter);
  });

  // count report and send email
  Object.keys(reportStacks).forEach((id) => {
    const countReporters = reportStacks[id].length;
    if (countReporters >= k) {
      // send emails
      reportStacks[id].forEach((reporter) => {
        emailStacks[reporter]++;
      });
    }
  });

  return id_list.map((id) => emailStacks[id]);
}
